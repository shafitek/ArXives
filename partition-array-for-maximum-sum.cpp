// https://leetcode.com/problems/partition-array-for-maximum-sum/

class Solution {
public:
    int n;
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        vector<int> memo(n, -1);
        
        return f(arr, memo, k, 0);
    }
    
    int f(vector<int> &arr, vector<int> &memo, int &k, int idx) {
        if (idx >= n) 
            return 0;
        
        if (memo[idx] != -1) 
            return memo[idx];
        
        if(k > n-idx) {
            return maxSubArray(arr, idx, n-1) * (n-idx);
        }
        
        int max_sum = INT_MIN;
        for(int p = 0; p < k; p++) {
            max_sum = max(
                max_sum,
                maxSubArray(arr, idx, idx+p) * (p+1) + f(arr, memo, k, idx+p+1)
            );   
        }
        
        memo[idx] = max_sum;
        
        return max_sum != INT_MIN ? max_sum : 0;
    }
    
    int maxSubArray(vector<int> &arr, int l, int r) {
        int max_val = INT_MIN;
        for(int i = l; i <= r; i++) {
            max_val = max(arr[i], max_val);
        }
        return max_val;
    }
};