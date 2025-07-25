class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        // Create a 2D DP array with (m+1) x (n+1) size
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    // Characters match → add 1 to the diagonal value
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // Characters don't match → take max of left and top cell
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The bottom-right cell contains the final answer
        return dp[m][n];
    }
};
