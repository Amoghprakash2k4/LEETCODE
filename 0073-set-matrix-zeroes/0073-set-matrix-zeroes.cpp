class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n, 1); // Initialize with 0
        vector<int> col(m, 1);

        // First pass: mark rows and columns
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }

        // Second pass: set matrix elements to 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!row[i] || !col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
