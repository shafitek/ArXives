// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> soln;
        unordered_map<int, vector<int>> h_map;
        
        for(int i = 0; i < groupSizes.size(); i++) {
            h_map[groupSizes[i]].push_back(i);
        }
        
        for(auto const &[key, val]:h_map) {
            if(val.size() == key) {
                soln.push_back(val);
            } else if (val.size() > key) {
                int idx = 0;
                for(int j = 0; j < val.size()/key; j++) {
                    vector<int> tmp;
                    for(int k = 0; k < key; k++) tmp.push_back(val[idx+k]);
                    idx+=key;
                    soln.push_back(tmp);
                }
            }
        }
        
        return soln;
    }
};