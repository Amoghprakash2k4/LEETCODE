class Solution {
public:
    bool dfsCheck(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, vector<int>& checked) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathVis, checked)) return true; // cycle found
            }
            else if (pathVis[it]) {
                return true; // cycle detected
            }
        }

        pathVis[node] = 0;   // backtrack
        checked[node] = 1;   // mark as safe
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        
        // normal adjacency (don’t reverse)
        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                adj[i].push_back(it);
            }
        }

        vector<int> vis(n, 0), pathVis(n, 0), checked(n, 0);
        vector<int> safenodes;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfsCheck(i, adj, vis, pathVis, checked);
            }
        }

        for (int i = 0; i < n; i++) {
            if (checked[i]) safenodes.push_back(i);
        }
        return safenodes;
    }
};
