class Solution {
public:
    int f(int i, int j, vector<vector<int>>& dp, string word1, string word2){
        if(i < 0 ) return j+1;
        if( j < 0) return i+1;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) return dp[i][j] = f(i-1, j-1, dp, word1, word2);
        else{
            int insertOp = f(i, j-1, dp, word1, word2);
            int deleteOp = f(i-1, j, dp, word1, word2);
            int replaceOp = f(i-1, j-1, dp, word1, word2);

            return dp[i][j] = 1 + min(insertOp, min(deleteOp, replaceOp));

            
        }

    }


    int minDistance(string word1, string word2) {
        int i = word1.size(), j = word2.size();

        vector<vector<int>> dp(i+1, vector<int>(j+1, -1));

        return f(i-1, j-1, dp, word1, word2);
    }
};