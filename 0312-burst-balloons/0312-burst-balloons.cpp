class Solution {
public:
    int maxCoins(vector<int>& a) {
    int n = a.size();

    // Add 1 at both ends for easier calculation
    a.push_back(1);
    a.insert(a.begin(), 1);

    // DP table
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // Fill dp table
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (i > j) continue;  // invalid interval

            int maxi = INT_MIN;

            // Choose the last balloon to burst between [i...j]
            for (int ind = i; ind <= j; ind++) {
                int cost = a[i - 1] * a[ind] * a[j + 1]
                         + dp[i][ind - 1] + dp[ind + 1][j];

                maxi = max(maxi, cost);
            }

            dp[i][j] = maxi;
        }
    }

    return dp[1][n];
    }
};