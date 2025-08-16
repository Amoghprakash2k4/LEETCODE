class Solution {
public:
// int countpath(int i, int j,vector<vector<int>>& dp){
//     if(i==0 && j==0) return 1;
//         if(i<0 || j<0) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         int left = countpath(i-1,j,dp);
//         int right = countpath(i,j-1,dp);
//         return dp[i][j]=left+right;
// }
//     int uniquePaths(int m, int n) {
//         // // We want to compute C(m+n-2, m-1)
//         // long long res = 1;
//         // int N = m + n - 2;
//         // int k = min(m - 1, n - 1); 
//         // for (int i = 1; i <= k; ++i) {
//         //     res = res * (N - k + i) / i;
//         // }
//         // return (int)res;
//         vector<vector<int>> dp(m, vector<int>(n, -1));

//         int i = m-1, j=n-1;
        // return countpath(i,j,dp);
        // --------------------
        

        int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Base case: starting cell
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    int up = 0, left = 0;
                    if (i > 0) up = dp[i-1][j];
                    if (j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }

        return dp[m-1][n-1];
        }
        
};
