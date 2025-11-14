class Solution {
public:
int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i=m-1 ; i>=0 ; i--){
            for(int j=n-1 ; j>=0 ; j--){
                if(text1[i] == text2[j])
                    dp[i][j] = 1+dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];



        // vector<int> prev(n + 1, 0), curr(n + 1, 0);

        // for (int i = 1; i <= m; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         if (text1[i - 1] == text2[j - 1]) {
        //             curr[j] = prev[j - 1] + 1;   
        //         } else {
        //             curr[j] = max(prev[j], curr[j - 1]); // mismatch → max(top, left)
        //         }
        //     }
        //     prev = curr; // move current row to previous row
        // }

        // return prev[n];
}
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return longestCommonSubsequence(s, t);
    }
};