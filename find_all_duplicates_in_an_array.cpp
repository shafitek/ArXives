// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> soln;

        int nums_length = nums.size();
        int idx = 0;

        for (auto &num : nums)
        {
            idx = num > 0 ? (num - 1) : (-num - 1);
            if (nums[idx] > 0)
                nums[idx] = -nums[idx];
            else
                soln.push_back(idx+1);
        }

        return soln;
    }
};