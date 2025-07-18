class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long left = 0, total = 0, maxFreq = 0;

        for (long long right = 0; right < nums.size(); ++right) {
            // Total increments needed to make nums[left..right] equal to nums[right]
            total += nums[right];

            // Window size is (right - left + 1), desired total would be nums[right] * window size
            // If total actual sum is less than desired total by more than k, shrink window
            while ((right - left + 1) * (long long)nums[right] - total > k) {
                total -= nums[left];
                ++left;
            }

            maxFreq = max(maxFreq, right - left + 1);
        }

        return maxFreq;
    }
};
