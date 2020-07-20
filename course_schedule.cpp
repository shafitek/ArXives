// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //   Kahn's Algorithm for cycle detection
        vector<vector<int>>& pr = prerequisites;
        int count = 0;
        vector<int> in_degree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        deque<int> pdeque;
        
        // Construct graph
        for (int i = 0; i < pr.size(); i++) {
            in_degree[pr[i][0]]++;
            graph[pr[i][1]].push_back(pr[i][0]);
        }
        
        // Deque
        for(int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) pdeque.push_back(i);
        }
        
        while(!pdeque.empty()) {
            int current = pdeque.back();
            pdeque.pop_back();
            count++;
            for(int i = 0; i < graph[current].size(); i++) {
                in_degree[graph[current][i]]--;
                if (in_degree[graph[current][i]] == 0) pdeque.push_back(graph[current][i]);
            }
        }
        
        return count == numCourses;
    }
};