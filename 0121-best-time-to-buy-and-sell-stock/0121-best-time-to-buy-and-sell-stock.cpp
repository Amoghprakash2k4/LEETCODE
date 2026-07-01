class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int minPrize = prices[0];
    int maxProfit = 0;

    for(int i=1 ; i<prices.size() ; i++){
        int currProfit = prices[i] - minPrize;
        maxProfit = max(maxProfit, currProfit);
        minPrize = min(minPrize, prices[i]);
    }
    return maxProfit;
    }

};