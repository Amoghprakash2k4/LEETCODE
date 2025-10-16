class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        
        vector<vector<int>> dp(rows, vector<int>(cols));

        for (int i = rows - 1; i >= 0; --i) {
            for (int j = cols - 1; j >= 0; --j) {
                if (i == rows - 1 && j == cols - 1)
                    dp[i][j] = max(1, 1 - dungeon[i][j]);
                else if (i == rows - 1)
                    dp[i][j] = max(1, dp[i][j + 1] - dungeon[i][j]);
                else if (j == cols - 1)
                    dp[i][j] = max(1, dp[i + 1][j] - dungeon[i][j]);
                else {
                    int next_min = min(dp[i][j + 1], dp[i + 1][j]);
                    dp[i][j] = max(1, next_min - dungeon[i][j]);
                }
            }
        }

        return dp[0][0];
    }
};
