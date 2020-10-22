// https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> soln(num+1, 0);
        
        // Use the fact that when you multiply binary numbers by 2,
        // it just appends a 0 to that bunary number.
        // For example, 9 - 1001, 18 - 10010
        for(int i = 1; i <= num; i++) {
            soln[i] = soln[i/2] + i % 2;
        }
        
        return soln;
    }
};