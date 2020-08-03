// https://leetcode.com/problems/water-bottles/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int soln = numBottles;
        
        int bottles_left = numBottles;
        
        while(bottles_left >= numExchange) {
            soln += bottles_left/numExchange;
            bottles_left = bottles_left % numExchange + bottles_left/numExchange;
        }
                
        return soln;
    }
};