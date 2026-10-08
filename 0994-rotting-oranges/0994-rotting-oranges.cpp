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
    }
};
