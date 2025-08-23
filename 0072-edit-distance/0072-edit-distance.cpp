class Solution {
public:
    // int f(int i, int j, vector<vector<int>>& dp, string word1, string word2){
    //     if(i < 0 ) return j+1;
    //     if( j < 0) return i+1;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(word1[i] == word2[j]) return dp[i][j] = f(i-1, j-1, dp, word1, word2);
    //     else{
    //         int insertOp = f(i, j-1, dp, word1, word2); //insert an ectra word, move j and stay i at the same location
    //         int deleteOp = f(i-1, j, dp, word1, word2); // delete the ith letter and search for other possible keeping j same
    //         int replaceOp = f(i-1, j-1, dp, word1, word2); // replace i with jthe word and move both i and j

    //         return dp[i][j] = 1 + min(insertOp, min(deleteOp, replaceOp));

            
    //     }

    // }


    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        for(int i = 0 ; i<=m ; i++) dp[i][0] = i;
        for(int i = 0 ; i<=n ; i++) dp[0][i] = i;

        for(int i =1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(word1[i-1] == word2[j-1])   
                    dp[i][j] = dp[i-1][j-1];
                else{
                    int insertOp = dp[i][j-1]; //insert an ectra word, move j and stay i at the same location
                    int deleteOp = dp[i-1][j]; // delete the ith letter and search for other possible keeping j same
                    int replaceOp = dp[i-1][j-1]; // replace i with jthe word and move both i and j

                     dp[i][j] = 1 + min(insertOp, min(deleteOp, replaceOp));
                }
            }
        }
        return dp[m][n];
    }
};