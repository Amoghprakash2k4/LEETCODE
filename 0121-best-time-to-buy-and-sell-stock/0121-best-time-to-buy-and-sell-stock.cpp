class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprize=prices[0];
        int maxprofit=0;
        for(int i=1; i< prices.size(); i++){
            int cost = prices[i]-minprize;
            maxprofit = max(maxprofit, cost);
            minprize = min(minprize, prices[i]);
        }
        return maxprofit;
    }
};