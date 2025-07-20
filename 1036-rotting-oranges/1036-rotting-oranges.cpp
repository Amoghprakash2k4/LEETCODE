// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int rows = grid.size();
//         int cols = grid[0].size();
//         queue<pair<int, int>> q;
//         int fresh = 0;

//         // Step 1: Push all rotten oranges into queue
//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++) {
//                 if (grid[i][j] == 2) {
//                     q.push({i, j});
//                 } else if (grid[i][j] == 1) {
//                     fresh++;
//                 }
//             }
//         }

//         if (fresh == 0) return 0;

//         int time = -1;
//         int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // up, down, left, right

//         // Step 2: BFS from all initially rotten oranges
//         while (!q.empty()) {
//             int size = q.size();
//             time++;
//             while (size--) {
//                 auto [x, y] = q.front(); q.pop();
//                 for (int d = 0; d < 4; d++) {
//                     int nx = x + dir[d][0];
//                     int ny = y + dir[d][1];
//                     if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
//                         grid[nx][ny] = 2;
//                         fresh--;
//                         q.push({nx, ny});
//                     }
//                 }
//             }
//         }

//         return fresh == 0 ? time : -1;
//     }
// };


class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& time, int x, int y, int t) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Boundary & base cases
        if (x < 0 || y < 0 || x >= rows || y >= cols)
            return;
        
        if (grid[x][y] == 0) return; // Empty cell
        if (grid[x][y] == 2 && t != 0) return; // Already rotten and not starting point

        // If already visited with less or equal time, skip
        if (time[x][y] <= t) return;
        
        // Update time
        time[x][y] = t;
        
        // Spread in all 4 directions
        dfs(grid, time, x + 1, y, t + 1);
        dfs(grid, time, x - 1, y, t + 1);
        dfs(grid, time, x, y + 1, t + 1);
        dfs(grid, time, x, y - 1, t + 1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> time(rows, vector<int>(cols, INT_MAX));
        
        // Start DFS from all initially rotten oranges
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    dfs(grid, time, i, j, 0);
                }
            }
        }
        
        int result = 0;
        // Find the max time taken to rot all fresh oranges
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    if (time[i][j] == INT_MAX) return -1; // unreachable fresh orange
                    result = max(result, time[i][j]);
                }
            }
        }
        return result;
    }
};

