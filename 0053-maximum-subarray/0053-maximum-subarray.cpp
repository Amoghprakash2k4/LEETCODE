class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // Either continue the subarray or start new from current element
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
