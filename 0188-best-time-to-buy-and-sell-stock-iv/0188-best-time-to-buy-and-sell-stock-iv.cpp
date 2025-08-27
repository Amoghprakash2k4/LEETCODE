class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

        for (int ind = n-1; ind >= 0; ind--) {
            for (int transaction = 2*k-1; transaction >= 0; transaction--) {
                if (transaction % 2 == 0) { // buy
                    dp[ind][transaction] = max(-prices[ind] + dp[ind+1][transaction+1],
                                               dp[ind+1][transaction]);
                } else { // sell
                    dp[ind][transaction] = max(prices[ind] + dp[ind+1][transaction+1],
                                               dp[ind+1][transaction]);
                }
            }
        }
        return dp[0][0];   // ✅ inside the function now
    }
};
