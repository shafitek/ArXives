// https://leetcode.com/problems/subrectangle-queries/submissions/

class SubrectangleQueries {
public:
    vector<vector<int>> matrix;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        this->matrix = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        if (row1 < 0 || row1 > matrix.size() || col1 < 0 || col1 > matrix[0].size()) return;
        if (row2 < 0 || row2 > matrix.size() || col2 < 0 || col2 > matrix[0].size()) return;
        
        for(int i = row1; i <= row2; i++) {
            for(int j = col1; j <= col2; j++) matrix[i][j] = newValue;
        }
    }
    
    int getValue(int row, int col) {
        return (row < 0 || row > matrix.size() || col < 0 || col > matrix[0].size()) ? -1 : matrix[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */