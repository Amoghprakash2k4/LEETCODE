class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprize=prices[0];
        int maxprofit=0;
        for(int i=1; i< prices.size(); i++){
            int currprofit = prices[i]-minprize;        //profit ill make by buying mini and selling on ith day
            maxprofit = max(maxprofit, currprofit);
            minprize = min(minprize, prices[i]);
        }
        return maxprofit;
    }
};