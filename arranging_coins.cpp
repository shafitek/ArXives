// https://leetcode.com/problems/arranging-coins/

class Solution {
public:
    int arrangeCoins(int n) {
        unsigned long int sum = 0;
        unsigned long int i = 1;
        
        while(sum+i <= n) {
            sum += i;
            i++;
        }
        
        return i-1;
    }
};