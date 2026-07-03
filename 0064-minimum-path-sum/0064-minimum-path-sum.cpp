class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // int m = grid.size();           // Total number of rows
        // int n = grid[0].size();        // Total number of columns

        // vector<int> prev(n,0),curr(n,0);
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(i==0 && j==0) curr[j] = grid[i][j] ;
        //         else{
        //             int up = grid[i][j];
        //             if(i > 0) up += prev[j];
        //             else up+=1e9;

        //             int left = grid[i][j];
        //             if(j > 0) left += curr[j-1];
        //             else left += 1e9;
                                    
        //             curr[j] = min(up, left);

        //         }
        //     }
        //     prev = curr;
        // }
        // return prev[n-1];

        int m = grid.size();
        int n = grid[0].size();

        vector<int>prev(n,0), cur(n,0);

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(i==0 && j==0)
                    cur[j] = grid[i][j];
                else{
                int up = grid[i][j];
                if(i>0) up += prev[j];
                else up = 1e9;

                int left = grid[i][j];
                if(j>0) left += cur[j-1];
                else left = 1e9;

                cur[j] = min(left, up);
                }
            }
                prev = cur;
            }
            
        return prev[n-1];
    }
};
