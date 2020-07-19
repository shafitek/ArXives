// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> soln;
        generate(n, 1, 0, soln);
        return soln;
    }
    
    void generate(int &n, int for_par, int back_par, vector<string> &soln, string passed_down="(") {
        if (for_par == n) {
            for (int i = back_par; i < for_par; i++) passed_down += ")";
            soln.push_back(passed_down);
            return;
        }
        
        generate(n, for_par+1, back_par, soln, passed_down+"(");
        if (back_par < for_par) generate(n, for_par, back_par+1, soln, passed_down+")");
    }
    
};