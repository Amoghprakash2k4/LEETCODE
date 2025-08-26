class Solution {
public:
    // int profit(vector<int>& prices, int n, int buy, int ind, vector<vector<int>>& dp) {
    //     if (ind == n) return 0;

    //     if (dp[ind][buy] != -1) return dp[ind][buy];

    //     if (buy) {
    //         // Either buy today or skip
    //         dp[ind][buy] = max(-prices[ind] + profit(prices, n, 0, ind + 1, dp),
    //                             profit(prices, n, 1, ind + 1, dp));
    //     } else {
    //         // Either sell today or skip
    //         dp[ind][buy] = max(prices[ind] + profit(prices, n, 1, ind + 1, dp),
    //                             profit(prices, n, 0, ind + 1, dp));
    //     }

    //     return dp[ind][buy];
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int>(2, -1));  // dp[ind][buy]
        dp[n][0]=0,dp[n][1]=0;
        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int buy=0 ; buy<=1 ; buy++){
                if (buy) {
            // Either buy today or skip
            dp[ind][buy] = max(-prices[ind] + dp[ind+1][0],
                               dp[ind+1][1]);
        } else {
            // Either sell today or skip
            dp[ind][buy] = max(prices[ind] + dp[ind+1][1],
                               dp[ind+1][0]);
        }
            }
        }
        return dp[0][1];
    }
};
