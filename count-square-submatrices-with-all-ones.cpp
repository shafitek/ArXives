// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int soln = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> prefix(m+1, vector<int> (n+1, 0));
        prefix[0][0] = matrix[0][0];
        
        for(int i = 1; i < m+1; i++) {
            for(int j = 1; j < n+1; j++) {
                if(matrix[i-1][j-1] == 0) continue;
                prefix[i][j] = min(prefix[i][j-1], min(prefix[i-1][j], prefix[i-1][j-1])) + 1;
                soln += prefix[i][j];
            }
        }
        
        return soln;
    }
};