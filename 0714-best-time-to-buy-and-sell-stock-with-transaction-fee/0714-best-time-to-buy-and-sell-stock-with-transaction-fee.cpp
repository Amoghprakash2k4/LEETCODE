class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));  // dp[ind][buy]
        vector<int> ahead(2,0), cur(2,0);
        ahead[0]=0,ahead[1]=0;
        for(int ind = n-1 ; ind >= 0 ; ind--){
            // for(int buy=0 ; buy<=1 ; buy++){
                // if (buy) {
            // Either buy today or skip
            cur[1] = max(-prices[ind] - fee + ahead[0],
                               ahead[1]);
        // } else {
            // Either sell today or skip
            cur[0] = max(prices[ind] + ahead[1],
                               ahead[0]);
        // }
        ahead = cur;
            }
        // }
        return ahead[1];
    }
};