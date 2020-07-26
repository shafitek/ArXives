// https://leetcode.com/problems/number-of-closed-islands/

class Solution
{
public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int soln = 0;
        for (int i = 1; i < grid.size() - 1; i++)
        {
            for (int j = 1; j < grid[0].size() - 1; j++)
            {
                if (grid[i][j] == 1)
                    continue;
                bool cnt = dfs(grid, i, j);
                if (cnt)
                    soln++;
            }
        }

        return soln;
    }

    bool dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1)
        {
            if (grid[i][j] == 0)
            {
                grid[i][j] = 1;
                return false;
            }
            return true;
        }
        if (grid[i][j] == 1)
            return true;

        grid[i][j] = 1;

        bool count = true;
        count &= dfs(grid, i + 1, j);
        count &= dfs(grid, i - 1, j);
        count &= dfs(grid, i, j + 1);
        count &= dfs(grid, i, j - 1);

        return count;
    }
};