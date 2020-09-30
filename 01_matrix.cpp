// https://leetcode.com/problems/01-matrix/

class Solution
{
public:
    int m, n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));

        queue<vector<int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    q.push({i, j});
                }
                else
                {
                    memo[i][j] = INT_MAX;
                }
            }
        }

        int x, y, nx, ny, distance = 0;
        while (!q.empty())
        {
            vector<int> node = q.front();
            x = node[0];
            y = node[1];
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = node[0] + dx[i], ny = node[1] + dy[i];
                distance = memo[x][y] + 1;

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || matrix[nx][ny] == 0 || distance >= memo[nx][ny])
                    continue;

                memo[nx][ny] = distance;
                q.push({nx, ny});
            }
        }

        return memo;
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

// TLE! INCOMPLETE!
// class Solution
// {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
//     {
//         vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size()));
//         for (int i = 0; i < matrix.size(); i++)
//         {
//             for (int j = 0; j < matrix[0].size(); j++)
//             {
//                 if (matrix[i][j] == 1)
//                     memo[i][j] = INT_MAX;
//             }
//         }

//         for (int i = 0; i < matrix.size(); i++)
//         {
//             for (int j = 0; j < matrix[0].size(); j++)
//             {
//                 if (matrix[i][j] == 1)
//                     continue;
//                 dfs(matrix, memo, i - 1, j, 1);
//                 dfs(matrix, memo, i, j + 1, 1);
//                 dfs(matrix, memo, i + 1, j, 1);
//                 dfs(matrix, memo, i, j - 1, 1);
//             }
//         }

//         return memo;
//     }

//     void dfs(vector<vector<int>> &matrix, vector<vector<int>> &memo, int i, int j, int count)
//     {
//         if (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size() && count < memo[i][j])
//         {
//             memo[i][j] = count;
//             dfs(matrix, memo, i - 1, j, count + 1);
//             dfs(matrix, memo, i, j + 1, count + 1);
//             dfs(matrix, memo, i + 1, j, count + 1);
//             dfs(matrix, memo, i, j - 1, count + 1);
//         }
//     }

//     void PrintMatrix(vector<vector<int>> &matrix)
//     {
//         for (int i = 0; i < matrix.size(); i++)
//         {
//             cout << "| ";
//             for (int j = 0; j < matrix[0].size(); j++)
//             {
//                 cout << matrix[i][j] << " | ";
//             }
//             cout << endl;
//         }
//     }
// };