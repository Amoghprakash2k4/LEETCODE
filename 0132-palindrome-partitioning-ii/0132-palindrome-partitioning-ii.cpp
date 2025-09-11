// class Solution {
// public:
    // bool ispalindrome(int i, int j, string s){
    //     while(i < j){
    //         if(s[i] != s[j]) return false;
    //         i++; j--;
    //     }
    //     return true;
    // }

//     // int f(int i, int n, string s, vector<int> &dp){
//     //     if(i==n) return 0;
//     //     int mincost = INT_MAX;
//     //     if(dp[i] != -1) return dp[i];
//     //     for(int j=i ; j <n ; j++){
//     //     if(ispalindrome(i, j, s)){
//     //         int cost = 1 + f(j+1, n, s, dp);
//     //         mincost = min(mincost, cost);
//     //     }
        
//     //     }
//     //     return dp[i] = mincost;

//     // }



//     int minCut(string s) {
//       int n = s.size();
//       vector<int> dp(n+1, 0);
//         dp[n]= 0;
//         for(int i=n-1 ; i>=0 ; i--){
//         int mincost = INT_MAX;
//         // if(dp[i] != -1) return dp[i];
//         for(int j=i ; j <n ; j++){
//                 if(ispalindrome(i, j, s)){
//                     int cost = 1 + dp[j+1];
//                     mincost = min(mincost, cost);
//                 }
//             dp[i] = mincost;
//         }
         
//         }
//       return dp[0] - 1;  
//     }
// };



class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        // Step 1: Precompute palindrome table
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len <= 2) isPal[i][j] = true;
                    else isPal[i][j] = isPal[i+1][j-1];
                }
            }
        }

        // Step 2: DP for min cuts
        vector<int> dp(n+1, 0);
        dp[n] = 0;

        for (int i = n-1; i >= 0; i--) {
            int mincost = INT_MAX;
            for (int j = i; j < n; j++) {
                if (isPal[i][j]) {
                    int cost = 1 + dp[j+1];
                    mincost = min(mincost, cost);
                }
            }
            dp[i] = mincost;
        }

        return dp[0] - 1;
    }
};
