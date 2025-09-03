class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // If start or end cell is blocked
        if (grid[0][0] != 0 || grid[n-1][m-1] != 0) return -1;

        // Distance matrix
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 1;  // starting cell counts as step 1

        // BFS queue -> {distance, {row, col}}
        queue<pair<int, pair<int,int>>> q;
        q.push({1, {0,0}});

        // 8 directions
        vector<vector<int>> dirs = {{0,1},{1,0},
                                    {0,-1},{-1,0},
                                    {1,1},{-1,-1},
                                    {1,-1},{-1,1}};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // If destination reached
            if (r == n-1 && c == m-1) return dis;

            // Explore 8 neighbors
            for (auto &d : dirs) {
                int newr = r + d[0];
                int newc = c + d[1];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
                    grid[newr][newc] == 0 && dis + 1 < dist[newr][newc]) {
                    
                    dist[newr][newc] = dis + 1;
                    q.push({dis + 1, {newr, newc}});
                }
            }
        }
        return -1;
    }
};
