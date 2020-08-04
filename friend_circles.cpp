// https://leetcode.com/problems/friend-circles/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int soln = 0;
        vector<vector<bool>> visited(M.size(), vector<bool>(M[0].size(), false));

        for(int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M[0].size(); j++) {
                if (!visited[i][j] && M[i][j] == 1) { Visit(M, visited, make_pair(i, j)); soln++;};
            }
        }
        // PrintMatrix(visited);
        return soln;
    }
    
    void Visit(vector<vector<int>>& M, vector<vector<bool>>& visited, pair<int, int> v) {
        if(v.first >= M.size() || v.second >= M.size()) return;
        
        visited[v.first][v.second] = true;
        visited[v.second][v.first] = true;
        
        for(int i = 0; i < M.size(); i++) {
            if (!visited[i][v.first] && M[i][v.first] == 1) {
                // cout << v.first << ", " << i << " -> " << i << ", " << v.first << endl;
                Visit(M, visited, make_pair(i, v.first));
            }
        }
    }
    
    template <class T>
    void PrintMatrix(vector<vector<T>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            cout << "| ";
            for (int j = 0; j < matrix[0].size(); j++)
            {
                cout << matrix[i][j] << " | ";
            }
            cout << endl;
        }
        cout << "-----" << endl;
    }
};