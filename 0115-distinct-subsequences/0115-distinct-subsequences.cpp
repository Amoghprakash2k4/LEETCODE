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


// This is converted to 2 vector curr and prev, since only prev and prevj-1 are required no need of 2 vector so only 1 vector is used to compute

// no need of else cause prev[j]= curr[j];



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

