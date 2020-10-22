// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

class Solution {
public:
    // f(arr, l=0, r=0) = 
    //      min(minSum, f(l, m-1) + f(m, r) + max(arr, l, m-1)*max(arr, m, r)) 
    /*
          MAX(L)*MAX(R)
            /      \
        SUMS(L)   SUMS(R)
            |       |
        [   L   |   R   ]
                m
    */
    int n;
    int mctFromLeafValues(vector<int>& arr) {
        n = arr.size();
        vector<vector<int>> memo(n, vector<int> (n, -1));
        
        return f(arr, memo, 0, n-1);
    }
    
    int f(vector<int>& arr, vector<vector<int>>& memo, int l, int r) {
        if(memo[l][r] != -1) return memo[l][r];
        
        int cnt = INT_MAX;
        for(int m = l+1; m <= r; m++) {
            cnt = min(cnt,
                    maxArray(arr, l, m-1) * maxArray(arr, m, r) +
                    f(arr, memo, l, m-1) +
                    f(arr, memo, m, r));
        }
        
        if(cnt != INT_MAX)
            memo[l][r] = cnt;
        
        return cnt != INT_MAX ? cnt : 0;
    }
    
    int maxArray(vector<int> &arr, int l, int r) {
        int max_val = arr[l];
        for(int i = l+1; i <= r; i++) {
            max_val = max(max_val, arr[i]);
        }
        return max_val;
    }
};