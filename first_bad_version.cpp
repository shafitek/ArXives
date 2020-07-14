// https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned long l = 0;
        unsigned long r = n;
        unsigned long mid;
        
        if (isBadVersion(0)) return 1;
        
        while(l <= r) {
            mid = (l + r)/2;
            if (isBadVersion(mid)) {
                r = mid - 1;
            } else {
                l = mid+1;
            }
        }
        
        return r+1;
        
    }
};