class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use hash sets to track seen numbers
        unordered_set<char> rowSet, colSet, boxSet;

        for (int i = 0; i < 9; i++) {
            rowSet.clear();
            colSet.clear();
            for (int j = 0; j < 9; j++) {
                // Row check
                char rowVal = board[i][j];
                if (rowVal != '.') {
                    if (rowSet.count(rowVal)) return false;
                    rowSet.insert(rowVal);
                }

                // Column check
                char colVal = board[j][i];
                if (colVal != '.') {
                    if (colSet.count(colVal)) return false;
                    colSet.insert(colVal);
                }
            }
        }

        // Check 3x3 sub-boxes
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                boxSet.clear();
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char val = board[boxRow + i][boxCol + j];
                        if (val != '.') {
                            if (boxSet.count(val)) return false;
                            boxSet.insert(val);
                        }
                    }
                }
            }
        }

        return true; // All checks passed
    }
};
