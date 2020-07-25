// https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        string soln = "";
        int str_len = secret.length();
        unordered_map<char, int> map_s;
        unordered_map<char, int> map_g;
        
        int bulls = 0;
        int cows = 0;
        
        for(int i = 0; i < str_len; i++) {
            if(secret[i] == guess[i]) {bulls++; continue;}
            map_s[secret[i]]++;
            map_g[guess[i]]++;
        }
        
        for(auto const &[key, val] : map_s) {
            if(map_g.count(key) > 0) cows += min(map_g[key], val); 
        }
        
        soln += to_string(bulls) + "A" + to_string(cows) + "B";
        
        return soln;
    }
};