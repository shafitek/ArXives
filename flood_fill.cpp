// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int orig_val = image[sr][sc];
        recurseFloodFill(image, sr, sc, newColor, orig_val);
        return image;
    }
    
    void recurseFloodFill(vector<vector<int>>& img, int r, int c, int& color, int &startPixel) {
        if ( (r < 0 || c < 0) || (r > img.size()-1 || c > img[0].size()-1) || img[r][c] == color || img[r][c] != startPixel ) return;
        img[r][c] = color;
        recurseFloodFill(img, r-1, c, color, startPixel);
        recurseFloodFill(img, r, c+1, color, startPixel);
        recurseFloodFill(img, r+1, c, color, startPixel);
        recurseFloodFill(img, r, c-1, color, startPixel);
    }
};