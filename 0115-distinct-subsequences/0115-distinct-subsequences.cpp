class Solution {
public:
    int numDistinct(string s, string t) {
        // int m = s.size(), n = t.size();
        // vector<double> dp(n + 1, 0);  // use double to prevent overflow (intermediate)
        // dp[0] = 1; // empty t is always subsequence

        // for (int i = 1; i <= m; i++) {
            
        //     for (int j = n; j >= 1; j--) {
        //         if (s[i - 1] == t[j - 1]) {
        //             dp[j] += dp[j - 1];
        //         }
        //     }
        // }
        // return (int)dp[n];

        int m = s.size(), n = t.size();
vector<vector<double>> dp(m+1, vector<double>(n+1, 0));
for(int i=0 ; i <= m ; i++) dp[i][0] = 1;
for(int j=1 ; j <= n ; j++) dp[0][j] = 0;

for(int i =1 ; i <= m ; i++){
    for(int j =1 ; j<=n ; j++){
        if(s[i-1] == t[j-1]){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];

        }
        else{
            dp[i][j] = dp[i-1][j];
        }
    }
}
return dp[m][n];



    }
};

