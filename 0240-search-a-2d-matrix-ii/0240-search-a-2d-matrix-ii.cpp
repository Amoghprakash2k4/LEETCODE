class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = 0;
        int col = n - 1;

        while (row < m && col >= 0) {
            int val = matrix[row][col];
            if (val == target) {
                return true;
            } else if (val > target) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
};
