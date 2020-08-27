// https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        if (rowIndex == 1) return {1, 1};
                
        vector<int> row = {1, 1};
        
        for(int i = 2; i <= rowIndex; i++) {
            vector<int> tmp(i+1, 1);
            
            for(int i = 1; i < tmp.size()-1; i++) {
                tmp[i] = row[i-1] + row[i];
            }
            row = tmp;
        }
        
        return row;
    }
};