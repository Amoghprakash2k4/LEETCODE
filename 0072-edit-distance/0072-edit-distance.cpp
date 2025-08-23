class Solution {
public:
 
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if(m == 0) return n;
        if(n == 0) return m;
        
        vector<int> prev(n+1, 0), curr(n+1, 0);

       
             for(int j = 0 ; j<=n ; j++) prev[j] = j;

            for(int i =1 ; i <= m ; i++){
            curr[0] = i;
            for(int j = 1 ; j <= n ; j++){
                if(word1[i-1] == word2[j-1])   
                    curr[j] = prev[j-1];
                else{
                    int insertOp = curr[j-1]; //insert an ectra word, move j and stay i at the same location
                    int deleteOp = prev[j]; // delete the ith letter and search for other possible keeping j same
                    int replaceOp = prev[j-1]; // replace i with jthe word and move both i and j

                     curr[j] = 1 + min(insertOp, min(deleteOp, replaceOp));
                }
            }
            prev = curr;
        }
        return curr[n];




    }
};