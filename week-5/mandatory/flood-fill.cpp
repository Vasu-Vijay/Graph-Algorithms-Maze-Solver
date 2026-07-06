void fill(vector<vector<int>>& image, int i, int j, int oldcolor, int newcolor) {
    int m = image.size();
    int n = image[0].size();
    if(i>=m || i<0 || j>=n || j<0) { return; }
    if(image[i][j] != oldcolor) { return; }
    image[i][j] = newcolor;
    fill(image, i+1, j, oldcolor, newcolor);
    fill(image, i-1, j, oldcolor, newcolor);
    fill(image, i, j+1, oldcolor, newcolor);
    fill(image, i, j-1, oldcolor, newcolor);
}

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) { return image; }
        fill(image, sr, sc, image[sr][sc], color);
        return image;
    }
};