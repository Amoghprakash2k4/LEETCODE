class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<bool> prev(k + 1, false), cur(k + 1, false);

        prev[0] = true;

        if (arr[0] <= k)
            prev[arr[0]] = true;

        for (int i = 1; i < n; i++) {
            cur[0] = true;

            for (int target = 1; target <= k; target++) {

                bool notTake = prev[target];

                bool take = false;
                if (arr[i] <= target)
                    take = prev[target - arr[i]];

                cur[target] = take || notTake;
            }
            prev = cur;
        }
        return prev[k];
    }

    // Main function to check if we can split the array into 2 subsets of equal sum
    bool canPartition(vector<int>& nums) {
        int totalsum = 0;

        // Step 1: Calculate total sum of all elements
        for(int i = 0; i < nums.size(); i++)
            totalsum += nums[i];

        // Step 2: If total sum is odd, it can never be divided equally
        if(totalsum % 2 == 1)
            return false;

        // Step 3: Otherwise, we just need to check if a subset equals half of total sum
        int target = totalsum / 2;

        // Step 4: Use subset sum function to check if such subset exists
        return subsetSumToK(nums.size(), target, nums);
    }
};
