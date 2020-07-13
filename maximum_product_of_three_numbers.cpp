// https://leetcode.com/problems/maximum-product-of-three-numbers/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        int d = INT_MAX, e = INT_MAX;
        
        size_t i = 0, j = 0;
        size_t k = 0;
        
        for(int n = 0; n < nums.size(); n++) {
            if (nums[n] > a) { 
                a = nums[n];
                i = n;
            }
        }
        
        for(int n = 0; n < nums.size(); n++) {
            if (n == i) continue;
            if (nums[n] > b) {
                b = nums[n];
                j = n;
            }
            if (nums[n] < d) {
                d = nums[n];
                k = n;
            }
        }
        
        for(int n = 0; n < nums.size(); n++) {
            if (n == i) continue;
            if ( n != j && nums[n] > c) {
                c = nums[n];
            }
            if (n != k && nums[n] < e) {
                e = nums[n];
            }
        }
        
        return (a*b*c > a*d*e) ? a*b*c : a*d*e;
        
    }
};