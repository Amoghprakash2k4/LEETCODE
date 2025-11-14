class Solution {
public:
    // Function to check if there exists a subset of 'arr' whose sum is equal to 'k'
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        // Create a DP table: dp[i][target] means 
        // "Can we make 'target' sum using elements from 0 to i?"
        vector<vector<bool>> dp(n, vector<bool>(k+1, false));

        // Base case: It's always possible to make sum = 0 (by taking no elements)
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }

        // Base case: If the first element itself is <= target, mark that sum as possible
        if(arr[0] <= k)
            dp[0][arr[0]] = true;

        // Fill the DP table for each element and target sum
        for(int ind = 1; ind < arr.size(); ind++) {
            for(int target = 1; target <= k; target++) {

                // Option 1: Don't include the current element
                bool nottake = dp[ind - 1][target];

                // Option 2: Include the current element (if it’s not bigger than target)
                bool take = false;
                if(arr[ind] <= target)
                    take = dp[ind - 1][target - arr[ind]];

                // If either option works, then it's possible to make this sum
                dp[ind][target] = take || nottake;
            }
        }

        // Final answer: can we form sum = k using all n elements?
        return dp[n - 1][k];
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
