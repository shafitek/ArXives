// https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        vector<int> og_slope = {coordinates[1][1] - coordinates[0][1], coordinates[1][0] - coordinates[0][0]};
        
        float orig_slope = og_slope[1] == 0 ? LONG_MAX : (float)og_slope[0]/(float)og_slope[1];
        
        vector<int> curr_slope = og_slope;
        
        float slope = orig_slope;
        
        for(int i = 1; i < coordinates.size()-1; i++) {
            curr_slope = {coordinates[i+1][1] - coordinates[i][1], coordinates[i+1][0] - coordinates[i][0]};
            slope = curr_slope[1] == 0 ? LONG_MAX : (float)curr_slope[0]/(float)curr_slope[1];
            if (orig_slope != slope) return false;
        }
            
        return true;
    }
};