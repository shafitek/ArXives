// https://leetcode.com/problems/baseball-game/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0;
        stack<int> stk;

        for(int i = 0; i < ops.size(); i++) {
            if (ops[i] == "+") {
                int tmp = stk.top();
                stk.pop();
                int tmp2 = stk.top();
                stk.push(tmp);
                stk.push(tmp+tmp2);
                sum += tmp + tmp2;
            } else if(ops[i] == "D") {
                sum += 2*stk.top();
                stk.push(2*stk.top());
            }else if(ops[i] == "C") {
                sum -= stk.top();
                stk.pop();
            } else {
                sum += stoi(ops[i]);
                stk.push(stoi(ops[i]));
            }
        }

        return sum;
    }
};