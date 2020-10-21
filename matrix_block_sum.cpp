https://leetcode.com/problems/matrix-block-sum/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> soln(m, vector<int> (n, 0));
        vector<vector<int>> prefix_sum(m, vector<int> (n, 0));
        
        prefix_sum[0][0] = mat[0][0];
        for(int i = 1; i < m; i++) {
            prefix_sum[i][0] = prefix_sum[i-1][0] + mat[i][0];
        }
        for(int j = 1; j < n; j++) {
            prefix_sum[0][j] = prefix_sum[0][j-1] + mat[0][j];
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1] + mat[i][j];
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int r0, c0, r1, c1;
                r0 = max(0, i-K);
                r1 = min(m-1, i+K);
                c0 = max(0, j-K);
                c1 = min(n-1, j+K);
                
                soln[i][j] = prefix_sum[r1][c1];
                soln[i][j] -= r0 != 0 ? prefix_sum[r0-1][c1] : 0;
                soln[i][j] -= c0 != 0 ? prefix_sum[r1][c0-1] : 0;
                soln[i][j] += (r0 == 0 || c0 == 0) ? 0 : prefix_sum[r0-1][c0-1];
            }
        }
                
        return soln;
    }
    
    void PrintMatrix(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            cout << "| ";
            for (int j = 0; j < matrix[0].size(); j++)
            {
                cout << matrix[i][j] << " | ";
            }
            cout << endl;
        }
        cout << "---" << endl;
    }
    
};