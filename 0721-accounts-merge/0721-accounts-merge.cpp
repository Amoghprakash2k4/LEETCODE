class Solution {
    private: 
        vector<int>parent, size;
public:
    int findparent(int x, vector<int>& parent){
        if(parent[x] == x) return x;
        return parent[x] = findparent(parent[x], parent);
    }
    void unionbySize(int x, int y){
        int pu = findparent(x, parent);
        int pv = findparent(y, parent);
        if(pu == pv) return;
        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);       
         unordered_map<string, int> mp;
        for(int i=0 ; i<accounts.size() ; i++){
            for(int j=1 ; j<accounts[i].size() ; j++){
                if(mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = i;
                }
                else{
                    unionbySize(i, mp[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> s(accounts.size());
        for(auto it:mp){
            string mail = it.first;
            int node = findparent(it.second, parent);
            s[node].push_back(mail);
        }


        vector<vector<string>> res;
        for(int i=0; i<s.size(); i++){
            if(s[i].size() == 0) continue;
            sort(s[i].begin(), s[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:s[i]){
                temp.push_back(it);
            }
            res.push_back(temp);
        }
        return res;
    }
};