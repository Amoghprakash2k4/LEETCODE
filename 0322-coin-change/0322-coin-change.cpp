class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // vector<vector<int>> dp(coins.size(), vector<int>(amount+1,INT_MAX));
        // for(int i=0 ; i<=amount ; i++){
        //     if(i%coins[0] == 0) dp[0][i] = i/coins[0];
        //     else dp[0][i] = INT_MAX;
        // }

        // for(int ind = 1 ; ind <coins.size() ; ind++){
        //     for(int target = 0 ; target <=amount ; target++){
        //         int nottake = dp[ind-1][target];

        //         int take = INT_MAX;
        //         if(coins[ind] <= target && dp[ind][target-coins[ind]] != INT_MAX){
        //             take = 1+dp[ind][target-coins[ind]];
        //         }
        //         dp[ind][target] = min(take, nottake);
        //     }
        // }
        // return dp[coins.size() - 1][amount] == INT_MAX ? -1 : dp[coins.size() - 1][amount];

        int n = coins.size();
        vector<int>curr(amount+1, INT_MAX), prev(amount+1, INT_MAX);
        for(int i=0 ; i<=amount ; i++){
            if(i%coins[0] == 0) prev[i] = i/coins[0];
        }

        for(int ind=1 ; ind<n ; ind++){
                // fill(curr.begin(), curr.end(), INT_MAX);
                // curr[0] = 0;
            for(int target = 0 ; target <= amount ; target++){
                int nottake = prev[target];
                int take = INT_MAX;
                if(coins[ind] <= target && curr[target - coins[ind]] != INT_MAX ){
                    take = 1+curr[target-coins[ind]];
                }

                curr[target] = min(take, nottake);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if (ans == INT_MAX) return -1;
        else return ans;
    }
};