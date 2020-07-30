// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Idea here is: Let j < i,
        // nums[1]+nums[2]+...+nums[i] - (nums[1]+nums[2]+...nums[j])
        // will give the sum of the window subarray between j and i.
        // if the cumulative_sum-k exists in the prefix map, then 
        // sum(nums[j]+...+nums[i]) must equal k.
        
        if(nums.size() == 1) return k==nums[0] ? 1: 0;
        
        int soln = 0;
        int cumulative_sum = 0;
        
        unordered_map<int, int> prefix_map;
        prefix_map[0]++;
        
        for(int i = 0; i < nums.size(); i++) {
            cumulative_sum += nums[i];
            if(prefix_map.find(cumulative_sum-k) != prefix_map.end()) soln+=prefix_map[cumulative_sum-k];
            prefix_map[cumulative_sum]++;
        }
        
        return soln;
    }
};