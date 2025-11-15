class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // dp[ind][buy]: max profit from day ind with buy/sell state
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base case:
        // dp[n][0] = dp[n][1] = 0 → after the last day, no profit can be made

        // Fill table from back (bottom-up)
        for (int ind = n - 1; ind >= 0; ind--) {
            // Case 1: allowed to buy
            dp[ind][1] = max(-prices[ind] + dp[ind + 1][0],  // buy today
                              dp[ind + 1][1]);               // skip buying

            // Case 2: currently holding, can sell
            dp[ind][0] = max(prices[ind] + dp[ind + 1][1],   // sell today
                              dp[ind + 1][0]);               // skip selling
        }

        // Start from day 0, allowed to buy → return dp[0][1]
        return dp[0][1];
    }
};
