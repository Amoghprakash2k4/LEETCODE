class Solution {
public:

    // int f(int i, vector<int>& arr, int k, int n, vector<int> &dp){
    //     if(i == n) return 0;
    //     if(dp[i] != -1) return dp[i];
    //     int len = 0;
    //     int maxi = INT_MIN;
    //     int maxAns = INT_MIN;
    //     for(int j = i; j < min(i + k, n); j++) {
    //         len++;
    //         maxi = max(maxi, arr[j]);  // maximum in current partition
    //         int sum = len * maxi + f(j + 1, arr, k, n, dp); // partition cost
    //         maxAns = max(maxAns, sum); // store best result
    //     }
    //     return dp[i] = maxAns;

    // }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        for(int i=n-1 ; i>=0 ; i--){
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = 0;
        for(int j = i; j < min(i + k, n); j++) {
            len++;
            maxi = max(maxi, arr[j]);  // maximum in current partition
            int sum = len * maxi + dp[j+1]; // partition cost
            maxAns = max(maxAns, sum); // store best result
        }
         dp[i] = maxAns;

        }
        return dp[0];
    }
};
// int maxSumAfterPartitioning(vector<int>& arr, int k) {
//     int n = arr.size();
//     vector<int> dp(n+1, 0); // dp[n] = 0 already
    
//     for(int i=n-1 ; i>=0 ; i--){
//         int len = 0;
//         int maxi = INT_MIN;
//         int maxAns = 0;  // <-- fix: start with 0 instead of INT_MIN

//         for(int j = i; j < min(i + k, n); j++) {
//             len++;
//             maxi = max(maxi, arr[j]);  
//             int sum = len * maxi + dp[j+1];  
//             maxAns = max(maxAns, sum); 
//         }
//         dp[i] = maxAns;
//     }
//     return dp[0];
// }
