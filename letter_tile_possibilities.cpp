// https://leetcode.com/problems/letter-tile-possibilities/

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int soln = backTracker(tiles);
        return soln;
    }
    
    int backTracker(string tile) {
        if (tile.length() == 1) return 1;
        
        unordered_set<char> charset;
        int num = 0;
        for(int i = 0; i < tile.length(); i++){
            if (charset.count(tile[i])) continue;
            charset.insert(tile[i]);
            num += 1 + backTracker(tile.substr(0, i) + tile.substr(i+1));
        }
        
        return num;
    }
    
};