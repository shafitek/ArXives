// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> soln;
        int n = intervals.size();
        
        if(n == 0) return soln;
        
        sort(intervals.begin(), intervals.end(), 
                [](const vector<int> &a, const vector<int> &b) {
                    return a[0] < b[0];
                });
        
        int l_idx = 0;
        int u_b = intervals[l_idx][1];
        for(int i = 1; i < n; i++) {
            if(intervals[i][1] > u_b) {
                if (intervals[i][0] > u_b) {
                    soln.push_back({intervals[l_idx][0], u_b});
                    l_idx = i;
                    u_b = intervals[i][1];
                } else {
                    u_b = intervals[i][1];
                }
            }
        }
        
        if(l_idx < n) {
            soln.push_back({intervals[l_idx][0], max(u_b,intervals[n-1][1])});
        }
        
        return soln;
    }
};