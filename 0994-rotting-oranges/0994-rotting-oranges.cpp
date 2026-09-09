class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int colm = grid[0].size();

        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> visited(rows, vector<int>(colm,0));
        int freshCount = 0;
        for(int i=0 ; i<rows ; i++){
            for(int j=0 ; j<colm ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    visited[i][j] = 1;
                }
                else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }

        if(freshCount == 0) return 0;

        int time = 0;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, -1, 0, 1};
        int count = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >=0 && nrow < rows && ncol >=0 && ncol < colm && visited[nrow][ncol] != 1 && grid[nrow][ncol] ==1)
                {
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, t+1});
                    count++;
                }
            }
        }
        if(freshCount == count) return time;
        return -1;
    }
};
