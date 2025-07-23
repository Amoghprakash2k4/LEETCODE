class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        vector<bool> col(n, false);         // columns
        vector<bool> diag1(2*n-1, false);   // main diagonals (row + col)
        vector<bool> diag2(2*n-1, false);   // anti-diagonals (row - col + n - 1)

        backtrack(0, n, board, col, diag1, diag2, res);
        return res;
    }

    void backtrack(int row, int n, vector<string>& board,
                   vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2,
                   vector<vector<string>>& res) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; ++c) {
            if (col[c] || diag1[row + c] || diag2[row - c + n - 1])
                continue;

            board[row][c] = 'Q';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = true;

            backtrack(row + 1, n, board, col, diag1, diag2, res);

            board[row][c] = '.';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = false;
        }
    }
};
