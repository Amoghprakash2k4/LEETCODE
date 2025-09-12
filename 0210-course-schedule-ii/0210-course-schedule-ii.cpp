// class Solution {
// public:
//     bool dfsCheck(int node, vector<int> adj[], vector<int>& vis, vector<int>&   pathVis, vector<int>& topo) {
//         vis[node] = 1;
//         pathVis[node] = 1;

//         // explore neighbors
//         for (auto it : adj[node]) {
//             if (!vis[it]) {
//                 if (dfsCheck(it, adj, vis, pathVis, topo)) return true; // cycle found
//             }
//             else if (pathVis[it]) {
//                 return true; // cycle detected
//             }
//         }

//         // backtrack
//         pathVis[node] = 0;
//         topo.push_back(node); // push when fully processed
//         return false;
//     }

//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<int> adj[numCourses];
//         for (auto &pre : prerequisites) {
//             // int course = pre[0];
//             // int prereq = pre[1];
//             adj[pre[1]].push_back(pre[0]); // prereq → course
//         }


//         vector<int> vis(numCourses, 0);
//         vector<int> pathVis(numCourses, 0);
//         vector<int> topo;

//         for (int i = 0; i < numCourses; i++) {
//             if (!vis[i]) {
//                 if (dfsCheck(i, adj, vis, pathVis, topo)) {
//                     return false; // cycle found → not possible
//                 }
//             }
//         }

//         if(topo.size() == numCourses ) return true;
//     }
// };


class Solution {
public:
    bool dfsCheck(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, vector<int>& topo) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathVis, topo)) return true; // cycle found
            }
            else if (pathVis[it]) {
                return true; // cycle detected
            }
        }

        pathVis[node] = 0;          // backtrack
        topo.push_back(node);       // postorder insert
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
                    return {}; // return empty vector if cycle found
                }
            }
        }

        reverse(topo.begin(), topo.end()); // reverse for correct topo order
        if ((int)topo.size() == numCourses) return topo;
        return {}; // just in case
    }
};
