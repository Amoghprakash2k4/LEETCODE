class Solution {
public:
    void dfs(vector<vector<int>> &vis, vector<vector<char>>& board, int row, int col ){
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] != 1 && board[nrow][ncol] == 'O') {
                        dfs(vis, board, nrow, ncol);
                    }
        }
    }

    void solve(vector<vector<char>>& board) {
             int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0 ; i<m ; i++){
            if(vis[0][i] == 0 && board[0][i] == 'O')
                dfs(vis, board, 0, i);
            if(vis[n-1][i] == 0 &&board[n-1][i] == 'O')
                dfs(vis, board, n-1, i);
        }
        for(int i=0 ; i<n ; i++){
            if(vis[i][0] == 0 && board[i][0] == 'O')
                dfs(vis, board, i, 0);
            if(vis[i][m-1] == 0 && board[i][m-1] == 'O')
                dfs(vis, board,i, m-1);
        }

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(vis[i][j] == 0 && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        // return board;
    }
};