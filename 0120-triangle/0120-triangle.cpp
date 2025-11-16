// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<int> front = triangle[n-1];  // start with last row
//         vector<int> curr(n, 0);

//         for (int i = n - 2; i >= 0; i--) {
//             for (int j = 0; j <= i; j++) {
//                 int d  = triangle[i][j] + front[j];
//                 int dg = triangle[i][j] + front[j+1];
//                 curr[j] = min(d, dg);
//             }
//             front = curr;  // ✅ update after finishing row
//         }

//         return front[0];
//     }
// };


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Create a 2D dp table of size n x n initialized to 0
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: last row is same as triangle's last row
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        // Fill the table from bottom to top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int down = triangle[i][j] + dp[i + 1][j];      // move down
                int diag = triangle[i][j] + dp[i + 1][j + 1];  // move diagonal
                dp[i][j] = min(down, diag);
            }
        }

        // The answer is stored at the top of the triangle
        return dp[0][0];
    }
};
