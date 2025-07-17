class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        for(int point : cardPoints) total+=point;
        int windowsize = n - k;
        int currsum= 0;
        for(int i = 0; i<windowsize ; i++) currsum+=cardPoints[i];
        int mini = currsum;
        for(int i = windowsize; i<n; ++i){
            currsum+=cardPoints[i] - cardPoints[i - windowsize];
            mini = min(mini, currsum);
        }
        return total-mini;
    }
};
