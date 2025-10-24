class Solution {
public:
    int n, m;
    
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Start DFS from the first land cell found
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return dfs(i, j, grid, visited);
                }
            }
        }
        return 0; // No land found
    }

private:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        // Out of bounds → contributes 1 to perimeter
        if (i < 0 || j < 0 || i >= n || j >= m)
            return 1;

        // Water → contributes 1 to perimeter
        if (grid[i][j] == 0)
            return 1;

        // Already visited → no contribution
        if (visited[i][j])
            return 0;

        visited[i][j] = 1;

        // Explore 4 directions
        int perimeter = 0;
        perimeter += dfs(i + 1, j, grid, visited);
        perimeter += dfs(i - 1, j, grid, visited);
        perimeter += dfs(i, j + 1, grid, visited);
        perimeter += dfs(i, j - 1, grid, visited);

        return perimeter;
    }
};
