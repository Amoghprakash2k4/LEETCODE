class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> prev(amount+1, 0),curr(amount+1, 0);

        for(int i =0 ; i<=amount ; i++){
            if(i%coins[0] == 0) prev[i]=  i/coins[0];
            else prev[i] = INT_MAX;
        }

        for(int ind = 1 ; ind < coins.size(); ind++){
            for(int t = 0 ; t<= amount ; t++){
                int nottake =prev[t];
                int take = INT_MAX;
                // if(coins[ind] <= t) take = 1 + curr[t-coins[ind]];
                 if (coins[ind] <= t && curr[t - coins[ind]] != INT_MAX) 
                        take = 1 + curr[t - coins[ind]];

                curr[t] = min(take,nottake);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};