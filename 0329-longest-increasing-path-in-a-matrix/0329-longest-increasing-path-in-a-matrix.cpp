class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (dp[i][j] != 0) return dp[i][j];  // already computed
        
        int best = 1; // the path includes the cell itself
        
        for (auto &dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                best = max(best, 1 + dfs(matrix, x, y));
            }
        }
        
        return dp[i][j] = best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        m = matrix.size();
        n = matrix[0].size();
        dp.assign(m, vector<int>(n, 0));
        int maxLen = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxLen = max(maxLen, dfs(matrix, i, j));
            }
        }
        
        return maxLen;
    }
};
