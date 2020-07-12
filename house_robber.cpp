class Solution
{
public:

    // BOTTOM UP
    int rob(vector<int> &nums)
    {
        int len = nums.size();

        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];

        nums[1] = max(nums[0], nums[1]);

        for (int i = 2; i < len; i++)
        {
            nums[i] = max(nums[i] + nums[i - 2], nums[i - 1]);
        }

        return nums[len - 1];
    }

    // TOP DOWN WITH MEMOIZATION
    int rob(vector<int> &nums)
    {
        int len = nums.size();

        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];

        vector<int> memo(len, -1);
        computeRobbing(nums, 0, memo, len);

        int max_money = 0;
        for (auto const &m : memo)
            max_money = max(m, max_money);

        return max_money;
    }

    int computeRobbing(vector<int> &nums, size_t idx, vector<int> &memo, int len)
    {
        if (idx > len - 1)
            return 0;
        if (idx == len - 1)
            return nums[idx];

        if (memo[idx] != -1)
            return memo[idx];

        memo[idx] = max(nums[idx] + computeRobbing(nums, idx + 2, memo, len),
                        computeRobbing(nums, idx + 1, memo, len));

        return memo[idx];
    }
};