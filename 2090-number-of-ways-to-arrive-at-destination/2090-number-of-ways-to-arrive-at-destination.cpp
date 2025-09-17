#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;

        vector<long long> dis(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        int mod = 1e9 + 7;

        dis[0] = 0;
        ways[0] = 1;
        q.push({0, 0});

        while (!q.empty()) {
            auto [di, node] = q.top();
            q.pop();

            if (di > dis[node]) continue; // skip outdated

            for (auto [adnode, d] : adj[node]) {
                long long newDist = di + d;

                if (newDist < dis[adnode]) {
                    dis[adnode] = newDist;
                    ways[adnode] = ways[node];
                    q.push({dis[adnode], adnode});
                } 
                else if (newDist == dis[adnode]) {
                    ways[adnode] = (ways[adnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};
