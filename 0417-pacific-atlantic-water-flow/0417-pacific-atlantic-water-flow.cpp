class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        
        // Directions: up, right, down, left
        vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        
        // DFS function
        function<void(int,int,vector<vector<bool>>&)> dfs = [&](int i, int j, vector<vector<bool>>& visited) {
            visited[i][j] = true;
            for (auto &dir : dirs) {
                int x = i + dir[0], y = j + dir[1];
                if (x >= 0 && x < n && y >= 0 && y < m &&
                    !visited[x][y] && heights[x][y] >= heights[i][j]) {
                    dfs(x, y, visited);
                }
            }
        };
        
        // Pacific Ocean (top row, left column)
        for (int i = 0; i < n; i++) dfs(i, 0, pacific);
        for (int j = 0; j < m; j++) dfs(0, j, pacific);
        
        // Atlantic Ocean (bottom row, right column)
        for (int i = 0; i < n; i++) dfs(i, m - 1, atlantic);
        for (int j = 0; j < m; j++) dfs(n - 1, j, atlantic);
        
        // Collect cells reachable by both oceans
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};
