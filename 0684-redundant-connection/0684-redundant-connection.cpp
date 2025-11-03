class Solution {
public:
    bool dfs(int src, int target, vector<vector<int>>& adj, vector<int>& visited) {
        if (src == target) return true;
        visited[src] = 1;
        for (int nbr : adj[src]) {
            if (!visited[nbr]) {
                if (dfs(nbr, target, adj, visited)) 
                    return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1); // adjacency list

        for (auto &e : edges) {
            int u = e[0], v = e[1];

            vector<int> visited(n+1, 0);

            // If u and v are already connected -> redundant edge
            if (!adj[u].empty() && !adj[v].empty()) { 
                if (dfs(u, v, adj, visited)) 
                    return e;
            }

            // Otherwise, add the edge
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};
