class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        vector<int> prev(m,0);
        // first row to be copied exactly as it is
        for(int i =0; i<m ; i++) prev[i] = matrix[0][i];

        for(int i=1 ; i<n ; i++){
            vector<int> curr(m,0);
            for(int j=0 ; j<m ; j++){
                int u = matrix[i][j]+prev[j];

                int dl = matrix[i][j];
                if(j-1 >= 0)  dl +=  prev[j-1];
                else  dl = 1e9;

                int dr = matrix[i][j];
                if(j+1 < m) dr +=  prev[j+1];
                else dr = 1e9; 

                curr[j] = min(u, min(dl, dr));
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};