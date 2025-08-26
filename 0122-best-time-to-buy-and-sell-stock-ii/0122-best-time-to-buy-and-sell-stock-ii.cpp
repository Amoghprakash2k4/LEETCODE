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
        
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));  // dp[ind][buy]
        vector<int> ahead(2,0), cur(2,0);
        ahead[0]=0,ahead[1]=0;
        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int buy=0 ; buy<=1 ; buy++){
                if (buy) {
            // Either buy today or skip
            cur[buy] = max(-prices[ind] + ahead[0],
                               ahead[1]);
        } else {
            // Either sell today or skip
            cur[buy] = max(prices[ind] + ahead[1],
                               ahead[0]);
        }
        ahead = cur;
            }
        }
        return ahead[1];
    }
};
