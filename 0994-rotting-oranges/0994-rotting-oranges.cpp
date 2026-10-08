class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();

            queue<pair<int, pair<int,int>>> q;
            vector<vector<bool>> visited(n, vector<bool>(m,false));

            int freshOranges = 0;
            int rottonOranges = 0;
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<m ; j++){
                    if(grid[i][j] == 2){
                        q.push({0, {i, j}});
                        visited[i][j] = true;
                    }
                    else if(grid[i][j] == 1){
                        freshOranges++;
                    }
                }
            }
            if(freshOranges == 0) return 0;

            int time = 0;
            vector<vector<int>> dirs = {
                                        {-1, 0},
                                        {0, 1},
                                        {1, 0},
                                        {0, -1}
                                    };
            while(!q.empty()){
                int i = q.front().second.first;
                int j = q.front().second.second;
                int t = q.front().first;
                time = max(time, t);
                q.pop();
                for(auto dir : dirs){
                    int row = i + dir[0];
                    int col = j + dir[1];

                    if(row < 0 || row>=n ||col<0 || col>=m || grid[row][col] != 1 || visited[row][col] == true)continue;

                    visited[row][col] = true;
                    rottonOranges++;
                    q.push({time+1, {row, col}});
                }
            }
        if(rottonOranges == freshOranges) return time;
        else return -1;






            // int n = grid.size();
            // int m = grid[0].size();

            // int preFreshOrranges = 0;
            // vector<vector<int>> vis(n, vector<int>(m, 0));
            // queue<pair<pair<int,int>,int>> q;
            // for(int i=0 ; i<n ; i++){
            //     for(int j=0 ; j<m ; j++){
            //         if(grid[i][j] == 2)
            //         {
            //             q.push({{i,j}, 0});
            //             vis[i][j] = 1;

            //         }
            //         else if(grid[i][j] == 1){
            //             preFreshOrranges++;
            //         }
            //     }
            // }
            // if(preFreshOrranges == 0)
            //     return 0;
            
            // int spoiledOranges = 0;
            // int time = 0;
            // int delrow[4] = {-1, 0, 1, 0};
            // int delcol[4] = {0, -1, 0, 1};
            // while(!q.empty()){
            //     int row = q.front().first.first;
            //     int col = q.front().first.second;
            //     int t = q.front().second;
            //     time = max(t, time);

            //     q.pop();
            //     for(int i=0 ; i<4 ; i++){
            //         int newRow = row+delrow[i];
            //         int newCol = col+delcol[i];

            //         if(newRow < 0 || newCol < 0 ||
            //         newRow >= n || newCol >= m)
            //             continue;

            //         if(vis[newRow][newCol] == 0 && grid[newRow][newCol] == 1) {
            //             vis[newRow][newCol] = 1;
            //             q.push({{newRow, newCol}, t + 1});
            //             spoiledOranges++;
            //         }
            //     }
            // }
            // if(spoiledOranges == preFreshOrranges) return time;
            // else return -1;

    }
};
