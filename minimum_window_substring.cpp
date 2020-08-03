// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        
        if ( s.length() == 0 || t.length() == 0 || t.length() > s.length()) return "";
        if (s.length() == 1 && t.length() == 1) return (s == t) ? s : "";
        
        unordered_map<char, int> index_map;
        unordered_map<char, int> c_map;
        int l(0);
        pair<vector<int>, int> soln_pair;
        
        soln_pair.first = {-1, -1};
        soln_pair.second = INT_MAX;
        
        for(int i = 0; i < t.length(); i++) {
            index_map[t[i]]++;
            c_map[t[i]] = 0;
        }
        
        for(int r = 0; r < s.length(); r++){
            if(c_map.find(s[r]) != c_map.end()) c_map[s[r]]++;
            while (doesItMatch(index_map, c_map) && l <= r) {
                // cout << "Match at l: " << l << " and r: " << r << ", ";
                if (soln_pair.second > r-l+1) {
                    soln_pair.first[0] = l;
                    soln_pair.first[1] = r;
                    soln_pair.second = r-l+1;
                }
                // cout << s.substr(l, r-l+1) << endl;
                if(c_map.find(s[l]) != c_map.end()) c_map[s[l]]--;
                l++;
            }
        }
        // cout << soln_pair.first[0] << " and " << soln_pair.first[1] << endl;
        return soln_pair.second == INT_MAX ? "" : s.substr(soln_pair.first[0], soln_pair.first[1]-soln_pair.first[0]+1); 
    }
    
    bool doesItMatch(unordered_map<char, int>& index_map, unordered_map<char, int>& c_map) {
        for(auto const &[key, val] : index_map) if (val > c_map[key]) return false;
        return true;
    }
    
};