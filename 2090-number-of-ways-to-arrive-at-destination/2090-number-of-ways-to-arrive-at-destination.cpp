class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long MOD = 1e9 + 7;
        
        // Step 1: Build adjacency list
        vector<vector<pair<int, long long>>> graph(n);
        for (auto &r : roads) {
            int u = r[0], v = r[1];
            long long time = r[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }

        // Step 2: Initialize distance and ways arrays
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        // Step 3: Min-heap for Dijkstra
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});  // {distance, node}

        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            if (currDist > dist[node]) continue;

            for (auto [nei, time] : graph[node]) {
                long long newDist = currDist + time;

                // Case 1: Found a shorter path
                if (newDist < dist[nei]) {
                    dist[nei] = newDist;
                    ways[nei] = ways[node];
                    pq.push({newDist, nei});
                }
                // Case 2: Found another shortest path
                else if (newDist == dist[nei]) {
                    ways[nei] = (ways[nei] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1] % MOD;
    }
};
