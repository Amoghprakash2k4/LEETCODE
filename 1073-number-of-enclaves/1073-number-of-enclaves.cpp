class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0 ; i<n ; i++) {
            if(grid[i][0] == 1 && vis[i][0] == 0) {
                q.push({i,0});
                vis[i][0] = 1;
            }
            if(grid[i][m-1] == 1 && vis[i][m-1] == 0) {
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
        }

        // top and bottom rows
        for(int j=0 ; j<m ; j++) {
            if(grid[0][j] == 1 && vis[0][j] == 0) {
                q.push({0,j});
                vis[0][j] = 1;
            }
            if(grid[n-1][j] == 1 && vis[n-1][j] == 0) {
                q.push({n-1,j});
                vis[n-1][j] = 1;
            }
        }
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow < n && nrow >= 0 && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] != 1 && grid[nrow][ncol] == 1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                } 
        }
        }
        int count = 0 ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(vis[i][j] == 0 && grid[i][j]== 1)
                    count++;
            }
        }
        return count;
    }
};