class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprize=prices[0];
        int maxprofit=0;
        for(int i=0; i< prices.size(); i++){
            if(prices[i] <= minprize){
                minprize = prices[i];
            }
            if(prices[i]-minprize > maxprofit){
                maxprofit =prices[i]-minprize;
            }
        }
        return maxprofit;
    }
};