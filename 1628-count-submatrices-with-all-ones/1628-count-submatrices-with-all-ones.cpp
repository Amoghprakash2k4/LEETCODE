class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // Step 1: Build histogram heights
        vector<vector<int>> height(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (mat[i][j] == 0) height[i][j] = 0;
                else height[i][j] = (i == 0 ? 1 : height[i-1][j] + 1);
            }
        }

        int ans = 0;

        // Step 2: For each row, count submatrices using monotonic stack
        for (int i = 0; i < m; i++) {
            vector<int> sum(n, 0);   // sum[j] = total submatrices ending at column j in this row
            stack<int> st;

            for (int j = 0; j < n; j++) {
                // Pop while stack top higher than current
                while (!st.empty() && height[i][st.top()] >= height[i][j]) {
                    st.pop();
                }

                if (!st.empty()) {
                    int prevIdx = st.top();
                    sum[j] = sum[prevIdx] + height[i][j] * (j - prevIdx);
                } else {
                    sum[j] = height[i][j] * (j + 1);
                }

                st.push(j);
                ans += sum[j];
            }
        }

        return ans;
    }
};
