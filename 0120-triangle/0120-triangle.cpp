class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front = triangle[n-1];  // start with last row
        vector<int> curr(n, 0);

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int d  = triangle[i][j] + front[j];
                int dg = triangle[i][j] + front[j+1];
                curr[j] = min(d, dg);
            }
            front = curr;  // ✅ update after finishing row
        }

        return front[0];
    }
};
