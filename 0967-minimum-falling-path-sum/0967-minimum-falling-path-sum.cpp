// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix[0].size();
//         int n = matrix.size();
//         vector<int> prev(m,0);
//         // first row to be copied exactly as it is
//         for(int i =0; i<m ; i++) prev[i] = matrix[0][i];

//         for(int i=1 ; i<n ; i++){
//             vector<int> curr(m,0);
//             for(int j=0 ; j<m ; j++){
//                 int u = matrix[i][j]+prev[j];

//                 int dl = matrix[i][j];
//                 if(j-1 >= 0)  dl +=  prev[j-1];
//                 else  dl = 1e9;

//                 int dr = matrix[i][j];
//                 if(j+1 < m) dr +=  prev[j+1];
//                 else dr = 1e9; 

//                 curr[j] = min(u, min(dl, dr));
//             }
//             prev = curr;
//         }
//         return *min_element(prev.begin(), prev.end());
//     }
// };



class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // dp[i][j] = minimum falling path sum to reach cell (i, j)
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case: first row = same as matrix
        for(int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Fill DP from row 1 to row n-1
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {

                int up = matrix[i][j] + dp[i-1][j];

                int leftDiag = 1e9;
                if(j - 1 >= 0)
                    leftDiag = matrix[i][j] + dp[i-1][j-1];

                int rightDiag = 1e9;
                if(j + 1 < m)
                    rightDiag = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min({up, leftDiag, rightDiag});
            }
        }

        // The answer is the minimum in the last row
        int ans = INT_MAX;
        for(int j = 0; j < m; j++)
            ans = min(ans, dp[n-1][j]);

        return ans;
    }
};
