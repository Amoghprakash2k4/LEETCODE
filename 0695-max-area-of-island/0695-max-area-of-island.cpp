class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxAre = 0;
        vector<vector<bool>> visited(n, vector<bool>(m));
        for(int i=0 ; i<n ; i++){
            int currmax = 0;
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    
                    currmax = dfs(i, j, grid, visited,n,m);
                    maxAre = max(maxAre, currmax);
                }
            }
            
        }
        return maxAre;
    }
    vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited,int n, int m ){
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || visited[i][j])
                 return 0;

        visited[i][j] = true;
        int area =1;
        for(auto &dir: dirs){
            int x = i+dir[0], y=j+dir[1];
           area+= dfs(x,y,grid,visited,n,m);
        }
        return area;
    }
};
