class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();           // Total number of rows
        int n = grid[0].size();        // Total number of columns

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;  // Start cell, do nothing
                else if (i == 0) grid[i][j] += grid[i][j - 1];         // Only from left
                else if (j == 0) grid[i][j] += grid[i - 1][j];         // Only from top
                else grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]); // Choose min(top, left)
            }
        }
        return grid[m - 1][n - 1]; // Bottom-right cell contains the min path sum
    }
};
