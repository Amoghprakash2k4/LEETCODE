class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i, j , grid,n, m);
                }
            }
        }
        return count;
    }
    vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    void dfs(int x, int y,vector<vector<char>>& grid, int n , int m){
        if(x<0 || x>=n || y<0 || y>=m || grid[x][y] != '1')
            return;
        
        grid[x][y] = '0';

        for(auto &dir :dirs){
            int i = x+dir[0], j= y+dir[1];
            dfs(i, j, grid, n, m);
        }
    }
};