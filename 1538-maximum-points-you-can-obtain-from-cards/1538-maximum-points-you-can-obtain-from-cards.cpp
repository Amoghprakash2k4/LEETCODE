class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        for (int point : cardPoints) total += point;

        if (k == n) return total;

        int windowSize = n - k;
        int currSum = 0;
        for (int i = 0; i < windowSize; ++i) {
            currSum += cardPoints[i];
        }

        int minSubarraySum = currSum;
        for (int i = windowSize; i < n; ++i) {
            currSum += cardPoints[i] - cardPoints[i - windowSize];
            minSubarraySum = min(minSubarraySum, currSum);
        }

        return total - minSubarraySum;
    }
};
