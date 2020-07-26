// https://leetcode.com/problems/verifying-an-alien-dictionary/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> h_map;
        
        for(int i = 0; i < order.length(); i++) {
            h_map[order[i]] = i;
        }
        
        for(int i = 0; i < words.size()-1; i++) {
            for(int j = 0; j < words[i].length(); j++) {
                if(h_map[words[i][j]] < h_map[words[i+1][j]]) break;
                if (j >= words[i+1].length()) return false;
                if(h_map[words[i][j]] > h_map[words[i+1][j]]) return false;
            }
        }
        
        return true;
    }
};