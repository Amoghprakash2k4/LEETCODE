class Solution {
public:
    void dfs(int city,vector<bool>& visited, vector<vector<int>>& adj){
        visited[city] = true;
        for(auto neighbour : adj[city]){
            if(!visited[neighbour]){
                dfs(neighbour, visited, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int i=0; i<n ; i++){
            for(int j=0; j<n ; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);

                }
            }
        }
        vector<bool> visited(n, false);
        int provinces =0;
        for(int i=0 ; i<n ; i++){
            if(visited[i] == false){
                provinces++;
                dfs(i, visited, adj);
            }
        }
            return provinces;


    }
};
