// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 && n == 1) return 1;
        
        vector<vector<int>> matrix( m, vector<int> (n) );
        
        for(int i = 0; i < m; i++) {
            matrix[i][n-1] = 1;
        }
        for(int i = 0; i < n; i++) {
            matrix[m-1][i] = 1;
        }
        matrix[m-1][n-1] = 0;
        
        // PrintMatrix(matrix);
        
        for(int i = m-2; i >= 0; i--){
            for(int j = n-2; j >=0; j--) {
                matrix[i][j] += matrix[i+1][j] + matrix[i][j+1];
            }
        }
        // PrintMatrix(matrix);
        return matrix[0][0];
    }
    
    void PrintMatrix(vector<vector<int>> &matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            cout << "| ";
            for(int j = 0; j < matrix[0].size(); j++) {
                cout << matrix[i][j] << " | ";
            }
            cout << endl;
        }
    }
};