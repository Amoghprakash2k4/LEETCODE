class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>> 
        > pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<int> dirX = {-1, 1, 0, 0};
        vector<int> dirY = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if (x == n-1 && y == m-1) return d;

            for (int k = 0; k < 4; k++) {
                int newr = x + dirX[k];
                int newc = y + dirY[k];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m) {
                    int effort = max(abs(heights[x][y] - heights[newr][newc]), d);
                    if (effort < dist[newr][newc]) {
                        dist[newr][newc] = effort;
                        pq.push({effort, {newr, newc}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};
