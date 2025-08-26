class Solution {
public:
    int profit(vector<int>& prices, int n, int buy, int ind, vector<vector<int>>& dp) {
        if (ind == n) return 0;

        if (dp[ind][buy] != -1) return dp[ind][buy];

        if (buy) {
            // Either buy today or skip
            dp[ind][buy] = max(-prices[ind] + profit(prices, n, 0, ind + 1, dp),
                                profit(prices, n, 1, ind + 1, dp));
        } else {
            // Either sell today or skip
            dp[ind][buy] = max(prices[ind] + profit(prices, n, 1, ind + 1, dp),
                                profit(prices, n, 0, ind + 1, dp));
        }

        return dp[ind][buy];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));  // dp[ind][buy]
        return profit(prices, n, 1, 0, dp);  // start at day 0, buy allowed
    }
};
