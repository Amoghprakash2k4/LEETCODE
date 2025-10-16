class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        
        vector<vector<long long>> dp(rows, vector<long long>(cols));

        for (int i = rows - 1; i >= 0; --i) {
            for (int j = cols - 1; j >= 0; --j) {
                if (i == rows - 1 && j == cols - 1)
                    dp[i][j] = max(1LL, 1LL - (long long)dungeon[i][j]);
                else if (i == rows - 1)
                    dp[i][j] = max(1LL, dp[i][j + 1] - (long long)dungeon[i][j]);
                else if (j == cols - 1)
                    dp[i][j] = max(1LL, dp[i + 1][j] - (long long)dungeon[i][j]);
                else {
                    long long next_min = min(dp[i][j + 1], dp[i + 1][j]);
                    dp[i][j] = max(1LL, next_min - (long long)dungeon[i][j]);
                }
            }
        }

        return (int)dp[0][0];
    }
};

