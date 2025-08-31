class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        int fresh = 0;

        // Step 1: Push all rotten oranges into queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0;

        int time = 0;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        int countFresh = 0;

        // Step 2: BFS from all initially rotten oranges
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols &&
                    vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    countFresh++;
                }
            }
        }

        // If all fresh became rotten
        if (countFresh == fresh) return time;
        return -1;  // some fresh oranges never rotted
    }
};
