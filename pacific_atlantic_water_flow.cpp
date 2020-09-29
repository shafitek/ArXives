// https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {    
        vector<vector<int>> soln;
        
        if (matrix.size() == 0) return soln;
        m = matrix.size();
        n = matrix[0].size();
        
        vector<vector<bool>> pacific (m, vector<bool> (n, false));
        vector<vector<bool>> atlantic (m, vector<bool> (n, false));

        for (int i = 0; i < n; i++)
        {
            checkFlow(matrix, pacific, 0, i, matrix[0][i]);
            checkFlow(matrix, atlantic, m - 1, i, matrix[m - 1][i]);
        }

        for (int i = 0; i < m; i++)
        {
            checkFlow(matrix, pacific, i, 0, matrix[i][0]);
            checkFlow(matrix, atlantic, i, n - 1, matrix[i][n - 1]);
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                    soln.push_back({i, j});
            }
        }
                        
        return soln;
    }
    
    void checkFlow(vector<vector<int>>& matrix, vector<vector<bool>>& ocean, int x, int y, int last_val) {
        if (x < 0 || x >=m || y < 0 || y >= n || ocean[x][y] || matrix[x][y] < last_val) 
            return;
        
        ocean[x][y] = true;
        checkFlow(matrix, ocean, x+1, y, matrix[x][y]);
        checkFlow(matrix, ocean, x, y+1, matrix[x][y]);
        checkFlow(matrix, ocean, x-1, y, matrix[x][y]);
        checkFlow(matrix, ocean, x, y-1, matrix[x][y]);
        
    }

    template <class T>
    void PrintMatrix(vector<vector<T>> &matrix)
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
        cout << "-----" << endl;
    }

};
