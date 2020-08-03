// https://leetcode.com/problems/xor-operation-in-an-array/

class Solution {
public:
    int xorOperation(int n, int start) {
        int soln = start;
        
        for(int i = 1; i < n; i++) {
            soln ^= start + 2*i;
        }
        
        return soln;
    }
};