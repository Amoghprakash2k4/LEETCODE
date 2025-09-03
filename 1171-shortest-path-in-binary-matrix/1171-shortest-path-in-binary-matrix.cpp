class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1]== 1) return -1;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 1;

        queue<pair<int, pair<int,int>>> q;
        q.push({1,{0,0}});

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            int d = node.first;   // \U0001f539 renamed
            int x = node.second.first;
            int y = node.second.second;

            if (x == n-1 && y == m-1) return d;

            for(int i= -1 ; i<=1 ; i++)
            {
                for(int j=-1 ; j<=1 ; j++)
                {
                    int newr = x+i;
                    int newc = y+j;

                    if(newr>=0 && newr < n && newc >=0 && newc < m && grid[newr][newc] == 0 && d + 1 < dist[newr][newc])
                    {
                        dist[newr][newc] = d + 1;
                        q.push({d + 1, {newr, newc}});
                    }
                }
            }
        }
        return -1;
    }
};
