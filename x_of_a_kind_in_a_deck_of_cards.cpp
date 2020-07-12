// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int deck_len = deck.size();
        
        if(deck_len < 2) return false;
         
        std::unordered_map<int, int> h_map;
        std::unordered_map<int, int>::iterator it;
        
        for(auto &num : deck){
            h_map[num]++;
        }
        
        int map_len = h_map.size();
        it = h_map.begin();
        
        if (map_len == 1) return true;
        
        int prev_val = it->second;
                
        it++;
        
        for( ; it!=h_map.end(); ++it){
            if (std::gcd(prev_val, it->second) == 1) return false;
            prev_val = std::gcd(prev_val, it->second);
        }
        return true;
    }
};