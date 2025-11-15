class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // dp[ind][buy] → max profit from index ind with buy/sell state
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base case: already initialized to 0

        // Bottom-up filling
        for (int ind = n - 1; ind >= 0; ind--) {
            // Case 1: we can buy
            dp[ind][1] = max(-prices[ind] -fee+ dp[ind + 1][0],
                              dp[ind + 1][1]);

            // Case 2: we can sell
            dp[ind][0] = max(prices[ind] + dp[ind + 1][1],
                              dp[ind + 1][0]);
        }

        // We start on day 0 with the option to buy
        return dp[0][1];






        
        
        // // vector<vector<int>> dp(n+1, vector<int>(2, -1));  // dp[ind][buy]
        // vector<int> ahead(2,0), cur(2,0);
        // ahead[0]=0,ahead[1]=0;
        // for(int ind = n-1 ; ind >= 0 ; ind--){
        //     // for(int buy=0 ; buy<=1 ; buy++){
        //         // if (buy) {
        //     // Either buy today or skip
        //     cur[1] = max(-prices[ind] - fee + ahead[0],
        //                        ahead[1]);
        // // } else {
        //     // Either sell today or skip
        //     cur[0] = max(prices[ind] + ahead[1],
        //                        ahead[0]);
        // // }
        // ahead = cur;
        //     }
        // // }
        // return ahead[1];
    }
};