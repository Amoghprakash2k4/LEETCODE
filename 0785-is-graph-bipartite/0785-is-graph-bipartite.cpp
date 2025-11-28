class Solution {
public:

    bool dfs(int i, int prevcolor, vector<int>& color,vector<vector<int>>& graph ){
        color[i] = prevcolor;
        for(auto it : graph[i]){
            if(color[it] == -1){
                if(dfs(it, !prevcolor, color, graph) == false) return false;
            }
            if(color[it] == prevcolor)  return false;
        }
    return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // int m = graph[0].size();
        vector<int> color(n,-1);

        for(int i=0 ; i<n ; i++){
            if(color[i] == -1){
                if(dfs(i,0, color, graph) == false)
                    return false;
            }
        }    
        return true;

    }
};