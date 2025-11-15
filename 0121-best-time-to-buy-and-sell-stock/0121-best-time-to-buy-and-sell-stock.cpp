class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base case: at the end, profit is 0 whether we can buy or not
        dp[n][0] = dp[n][1] = 0;

        // Fill DP table backwards
        for (int ind = n - 1; ind >= 0; ind--) {
            // If we can buy
            dp[ind][1] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);

            // If we can sell (only once)
            dp[ind][0] = max(prices[ind], dp[ind + 1][0]);
        }

        // Start with ability to buy on day 0
        return dp[0][1];
    }
};
