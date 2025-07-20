class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int oldColor, int newColor) {
        int rows = image.size();
        int cols = image[0].size();

        // Boundary or color mismatch condition
        if (x < 0 || x >= rows || y < 0 || y >= cols || image[x][y] != oldColor)
            return;

        image[x][y] = newColor;

        dfs(image, x+1, y, oldColor, newColor); // down
        dfs(image, x-1, y, oldColor, newColor); // up
        dfs(image, x, y+1, oldColor, newColor); // right
        dfs(image, x, y-1, oldColor, newColor); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if (oldColor != color)
            dfs(image, sr, sc, oldColor, color);
        return image;
    }
};
