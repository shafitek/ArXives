// https://leetcode.com/problems/valid-perfect-square/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        
        unsigned long i = 2;
        unsigned long j = num;
        unsigned long mid;
        
        while(i <= j) {
            mid = i + (j-i)/2;
            if (mid*mid == num) return true;
            if (mid*mid > num) j = mid-1;
            if (mid*mid < num) i = mid+1;
        }
        
        return false;
    }
};