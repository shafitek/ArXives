// https://leetcode.com/problems/pacific-atlantic-water-flow/

// INCOMPLETE!
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        vector<vector<int>> soln;

        if (matrix.size() == 0)
            return soln;
        int v = matrix.size();
        int h = matrix[0].size();

        vector<vector<bool>> pacific(matrix.size(), vector<bool>(matrix[0].size(), false));
        vector<vector<bool>> atlantic(matrix.size(), vector<bool>(matrix[0].size(), false));

        for (int i = 0; i < matrix[0].size(); i++)
        {
            pacific[0][i] = true;
            atlantic[matrix.size() - 1][i] = true;
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            pacific[i][0] = true;
            atlantic[i][matrix[0].size() - 1] = true;
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                isPacificReachable(matrix, pacific, i, j, matrix[i][j]);
            }
        }
        for (int i = 0; i < matrix.size() - 1; i++)
        {
            for (int j = 0; j < matrix[0].size() - 1; j++)
            {
                isAtlanticReachable(matrix, atlantic, i, j, matrix[i][j]);
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                    soln.push_back({i, j});
            }
        }
        // PrintMatrix(pacific);
        // PrintMatrix(atlantic);
        return soln;
    }

    bool isPacificReachable(vector<vector<int>> &matrix, vector<vector<bool>> &pacific, int i, int j, int last_val)
    {
        if ((i == 0 && (j >= 0 && j < matrix[0].size())) || (j == 0 && (i >= 0 && i < matrix.size())))
            return pacific[i][j] ? true : (pacific[i][j] || matrix[i][j] <= last_val) ? true : false;

        if (pacific[i][j])
            return true;
        if (matrix[i][j] > last_val)
            return false;

        pacific[i][j] = isPacificReachable(matrix, pacific, i - 1, j, matrix[i][j]) || isPacificReachable(matrix, pacific, i, j - 1, matrix[i][j]);

        return pacific[i][j];
    }

    bool isAtlanticReachable(vector<vector<int>> &matrix, vector<vector<bool>> &atlantic, int i, int j, int last_val)
    {
        if ((i == matrix.size() - 1 && (j >= 0 && j < matrix[0].size())) || (j == matrix[0].size() - 1 && (i >= 0 && i < matrix.size())))
            return (atlantic[i][j] || matrix[i][j] <= last_val) ? true : false;

        if (atlantic[i][j])
            return true;
        if (matrix[i][j] > last_val)
            return false;

        atlantic[i][j] = isAtlanticReachable(matrix, atlantic, i + 1, j, matrix[i][j]) || isAtlanticReachable(matrix, atlantic, i, j + 1, matrix[i][j]);

        return atlantic[i][j];
    }

    bool isOutOfBounds(int &v, int &h, int i, int j)
    {
        if (i < 0 || i >= v || j < 0 || j >= h)
            return false;
        return true;
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