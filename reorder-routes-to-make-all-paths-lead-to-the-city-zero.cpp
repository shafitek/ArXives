class Solution {
public:
    typedef vector<pair<vector<int>,vector<int>>> vector_pair;
    void dfs(vector_pair& graph, int n, vector<bool>& visited, int& count) {
        visited[n] = true;
        
        for(int i = 0; i < graph[n].first.size(); i++) {
            if(visited[graph[n].first[i]]) continue;
            dfs(graph, graph[n].first[i], visited, count);
        }
        
        for(int i = 0; i < graph[n].second.size(); i++) {
            if(visited[graph[n].second[i]]) continue;
            count++;
            dfs(graph, graph[n].second[i], visited, count);
        }
        
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        int soln = 0;
        
        // Convert to undirected graph first
        // NODE_i->([IN_NODES], [OUT_NODES])
        vector_pair graph(n, {{}, {}});
        
        for(int i = 0; i < n-1; i++){
            int s = connections[i][0];
            int t = connections[i][1];
            
            graph[t].first.push_back(s);
            graph[s].second.push_back(t);
        }
        
        vector<bool> visited(n, false);
        
        dfs(graph, 0, visited, soln);
        
        // for(int i = 0; i < n; i++) {
        //     vector<int> &f = graph[i].first;
        //     vector<int> &s = graph[i].second;
        //     cout << i << ": First->[ ";
        //     for(int j = 0; j < f.size(); j++)
        //         cout << f[j] << " ";
        //     cout << "]. Second->[ ";
        //     for(int j = 0; j < s.size(); j++)
        //         cout << s[j] << " ";
        //     cout << "]" << endl << endl;
        // }
        
        return soln;
    }
};