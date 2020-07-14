// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;

        int min_val = INT_MAX;
        int max_val = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (min_val > prices[i])
            {
                min_val = prices[i];
            }
            else if (prices[i] - min_val > max_val)
                max_val = prices[i] - min_val;
        }

        return max_val;
    }
};

// TIME LIMIT EXCEEDED!
// USING MEMOIZATION, DP SOLN
// class Solution
// {
// public:
//     int computeMaxProfit(vector<int> &prices, vector<int> &memo, int idx)
//     {
//         if (idx < 1)
//             return 0;

//         if (memo[idx] != -1)
//             return memo[idx];

//         int min_val = INT_MAX;
//         for (int i = idx - 1; i >= 0; i--)
//         {
//             min_val = min(prices[i], min_val);
//         }

//         memo[idx] = max(computeMaxProfit(prices, memo, idx - 1), prices[idx] - min_val);
//         return memo[idx];
//     }
//     int maxProfit(vector<int> &prices)
//     {
//         if (prices.size() == 0)
//             return 0;

//         vector<int> memo(prices.size(), -1);
//         computeMaxProfit(prices, memo, prices.size() - 1);

//         return max(0, memo[memo.size() - 1]);
//     }
// };