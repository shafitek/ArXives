// https://leetcode.com/problems/01-matrix/
// TLE! INCOMPLETE!
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 1)
                    memo[i][j] = INT_MAX;
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 1)
                    continue;
                dfs(matrix, memo, i - 1, j, 1);
                dfs(matrix, memo, i, j + 1, 1);
                dfs(matrix, memo, i + 1, j, 1);
                dfs(matrix, memo, i, j - 1, 1);
            }
        }

        return memo;
    }

    void dfs(vector<vector<int>> &matrix, vector<vector<int>> &memo, int i, int j, int count)
    {
        if (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size() && count < memo[i][j])
        {
            memo[i][j] = count;
            dfs(matrix, memo, i - 1, j, count + 1);
            dfs(matrix, memo, i, j + 1, count + 1);
            dfs(matrix, memo, i + 1, j, count + 1);
            dfs(matrix, memo, i, j - 1, count + 1);
        }
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
    }
};