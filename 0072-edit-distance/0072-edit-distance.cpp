class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        // Edge cases
        if (m == 0) return n;
        if (n == 0) return m;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base cases
        for (int i = 0; i <= m; i++) dp[i][n] = m - i; // delete remaining chars from word1
        for (int j = 0; j <= n; j++) dp[m][j] = n - j; // insert remaining chars from word2

        // Fill table bottom-up (reverse direction)
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1]; // no operation needed
                } else {
                    int insertOp = dp[i][j + 1];   // insert a char into word1
                    int deleteOp = dp[i + 1][j];   // delete a char from word1
                    int replaceOp = dp[i + 1][j + 1]; // replace a char
                    dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
                }
            }
        }

        return dp[0][0];
    }
};
