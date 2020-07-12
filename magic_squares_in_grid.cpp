// https://leetcode.com/problems/magic-squares-in-grid/
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int num_row = grid.size();
        int num_col = grid[0].size();
        
        if (num_row < 3 || num_col < 3) return 0;
        
        int h_stride = num_col - 3 + 1, v_stride = num_row - 3 + 1;
        int soln = 0;
        
        for(int v = 0; v < v_stride; v++) {
            for(int h = 0; h < h_stride; h++) {
                if (checkIfValidGrid(grid, v, h)) soln++;
            }
        }
        
        return soln;
    }
    
    bool checkIfValidGrid(vector<vector<int>>& grid, int v, int h) {
        unordered_map<int, int> mp_cnt = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}}; 
        for (int i = v; i < v+3; i++){
            for (int j = h; j < h+3; j++){
                if (grid[i][j] < 1 || grid[i][j] > 9) return false;
                mp_cnt[grid[i][j]]++;
            }
        }
        
        for (auto const& [key, val] : mp_cnt) {
            if (val != 1) return false;
        }
        
        int r_1 = 0, r_2 = 0, r_3 = 0, c_1 = 0, c_2 = 0, c_3 = 0, diag_l = 0, diag_r = 0;
        r_1 = grid[v][h] + grid[v][h+1] + grid[v][h+2];
        r_2 = grid[v+1][h] + grid[v+1][h+1] + grid[v+1][h+2];
        r_3 = grid[v+2][h] + grid[v+2][h+1] + grid[v+2][h+2];
        c_1 = grid[v][h] + grid[v+1][h] + grid[v+2][h];
        c_2 = grid[v][h+1] + grid[v+1][h+1] + grid[v+2][h+1];
        c_3 = grid[v][h+2] + grid[v+1][h+2] + grid[v+2][h+2];
        diag_l = grid[v][h] + grid[v+1][h+1] + grid[v+2][h+2];
        diag_r = grid[v+2][h] + grid[v+1][h+1] + grid[v][h+2];
        
        return (r_1 == r_2 && r_2 == r_3 && r_3 == c_1 && 
                c_1 == c_2 && c_2 == c_3 && c_3 == diag_l && 
                diag_l == diag_r) ? true : false;
    }
};