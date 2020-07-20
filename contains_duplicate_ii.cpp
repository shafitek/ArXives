// https://leetcode.com/problems/contains-duplicate-ii/

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {

        unordered_map<int, int> h_map;

        for (int i = 0; i < nums.size(); i++)
        {
            if (h_map.count(nums[i]) > 0 && i - h_map[nums[i]] <= k)
                return true;
            h_map[nums[i]] = i;
        }

        return false;
    }
};