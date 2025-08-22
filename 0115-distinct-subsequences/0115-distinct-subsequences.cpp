class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<double> dp(n + 1, 0);  // use double to prevent overflow (intermediate)
        dp[0] = 1; // empty t is always subsequence

        for (int i = 1; i <= m; i++) {
            // Traverse backwards to avoid overwriting previous states
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return (int)dp[n];
    }
};
