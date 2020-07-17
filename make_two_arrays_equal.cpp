// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> h_map;
        unordered_map<int, int> v_map;
        
        for(int i = 0; i < target.size(); i++) h_map[target[i]]++;
        
        for(int i = 0; i < arr.size(); i++) v_map[arr[i]]++;
        
        for (auto const &[key, val] : h_map) 
            if (v_map.count(key) == 0 || v_map[key] != val) return false;
        
            
        return true;
    }
};