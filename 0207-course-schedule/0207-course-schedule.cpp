class Solution {
public:

    bool dfsCheck(int node, vector<int> adj[], vector<int>& vis, vector<int>&   pathVis, vector<int>& topo) {
        vis[node] = 1;
        pathVis[node] = 1;

        // explore neighbors
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathVis, topo)) return true; // cycle found
            }
            else if (pathVis[it]) {
                return true; // cycle detected
            }
        }

        // backtrack
        pathVis[node] = 0;
        topo.push_back(node); // push when fully processed
        return false;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int> adj[numCourses];
        for (auto &pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); // prereq → course
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<int> topo;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfsCheck(i, adj, vis, pathVis, topo)) {
                    return {}; // cycle found → not possible
                }
            }
        }
        if(topo.size() == numCourses ) return true;
        else return false;
        // reverse(topo.begin(), topo.end()); // reverse for correct topological order
        
    }
};