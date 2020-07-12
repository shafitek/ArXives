// https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int soln = 0;
        int len = nums.size();
        int nummk = 0;
        std::unordered_map<int, int> h_map;
        std::unordered_map<int, int> soln_vec;
        
        if (k < 0) {
            return 0;
        }
        if (k == 0) {
            for (auto const& num : nums) {
                if (soln_vec.count(num) > 0 && soln_vec[num] == 1) {
                    soln++;
                    soln_vec[num]++;
                    continue;
                }
            
                soln_vec.insert({num, 1});
            }
        } else {
            for (auto const& num : nums) {

                nummk = num - k;

                if (h_map.count(nummk) > 0) continue;

                h_map.insert({nummk, num});
            }

            for (auto const& [key, val] : h_map) {
                if (h_map.count(val) > 0){
                    soln++;
                    // soln_vec.insert({val, h_map[val]});
                }
            }
        }
        
        // for (auto const& [key, val] : soln_vec) {
        //     cout << "(" << key << ", " << val << ")" << endl;
        // }
        
        return soln;
    }
};