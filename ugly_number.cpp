// https://leetcode.com/problems/ugly-number/

class Solution {
public:
    bool isUgly(int num) {
        if (num < 1) return false;
        if (num < 7) return true;
        
        int curr_num = num;
        int tmp;
        bool flag = false;
        while(curr_num > 1) {
            if(curr_num % 2 == 0) {
                tmp = curr_num/2;
                flag = true;
            }
            if (curr_num % 3 == 0) {
                tmp = curr_num/3;
                flag = true;
            }
            if (curr_num % 5 == 0) {
                tmp = curr_num/5;
                flag = true;
            }
            if (curr_num % 6 == 0) {
                tmp = curr_num/6;
                flag = true;
            }
            if (curr_num % 10 == 0) {
                tmp = curr_num/10;
                flag = true;
            }
            if (curr_num % 15 == 0) {
                tmp = curr_num/15;
                flag = true;
            }
            
            if (!flag) return false;
                
            curr_num = tmp;
            flag = false;
        }
        
        return true;
    }
};