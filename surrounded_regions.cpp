// https://leetcode.com/problems/surrounded-regions/

// TLE SOLUTION
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // PrintMatrix(board, false);
        if (board.size() == 0) return; 
        int r = board.size() - 1;
        int c = board[0].size() - 1;
        
        for(int i = 1; i < r; i++) {
            for(int j = 1; j < c; j++) {
                if (board[i][j] == 'O') {
                    vector<vector<int>> path;
                    dfs(board, i, j, r, c, path);
                }
            }
        }
        // PrintMatrix(board, false);
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j, int& r, int& c, vector<vector<int>>& path) {
        if(i == 0 || j == 0 || i == r || j == c) return board[i][j] == 'X';
        if (board[i][j] == 'X' || board[i][j] == 'Y') return true;
        
        board[i][j] = 'Y';
        bool top, right, left, down;
        
        top = board[i-1][j] == 'O' ? dfs(board, i-1, j, r, c, path) : true;
        right = board[i][j+1] == 'O' ? dfs(board, i, j+1, r, c, path) : true;
        down = board[i+1][j] == 'O' ? dfs(board, i+1, j, r, c, path) : true;
        left = board[i][j-1] == 'O' ? dfs(board, i, j-1, r, c, path) : true;
        
        bool ret;
        if (top && right && down && left) {
            board[i][j] = 'X';
            ret = true;
            path.push_back({i,j});
        } else {
            board[i][j] = 'O';
            ret = false;
            for(int i = 0; i < path.size(); i++) {
                board[path[i][0]][path[i][1]] = 'O';
            }
            path.clear();
        }
        
        return ret;
    }
    
    template <class T>
    void PrintMatrix(vector<vector<T>> &matrix, bool sub)
    {
        int start = sub ? 1 : 0;
        int r = sub ? matrix.size() - 1 : matrix.size();
        int c = sub ? matrix[0].size() - 1 : matrix[0].size();
        for (int i = start; i < r; i++)
        {
            cout << "| ";
            for (int j = start; j < c; j++)
            {
                cout << matrix[i][j] << " | ";
            }
            cout << endl;
        }
        cout << "-----" << endl;
    }
};