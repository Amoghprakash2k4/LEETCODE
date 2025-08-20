class Solution {
public:
    long long change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> prev(amount+1, 0), curr(amount+1, 0);

        // Base case: using only first coin
        for (int i = 0; i <= amount; i++) {
            prev[i] = (i % coins[0] == 0);
        }

        for (int ind = 1; ind < n; ind++) {
            fill(curr.begin(), curr.end(), 0);
            for (int t = 0; t <= amount; t++) {
                unsigned long long nottake = prev[t];
                unsigned long long take = 0;
                if (coins[ind] <= t) 
                    take = curr[t - coins[ind]];
                curr[t] = take + nottake;
            }
            prev = curr;
        }

        return (long long)prev[amount]; // cast back if needed
    }
};
