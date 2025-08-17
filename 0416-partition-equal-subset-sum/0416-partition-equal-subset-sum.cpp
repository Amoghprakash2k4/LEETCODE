class Solution {
public:
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Step 1: Create DP table (n x (k+1)), initialized with false
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Step 2: Base Case - sum = 0 is always possible
    for (int i = 0; i < n; i++) dp[i][0] = true;

    // Step 3: Base Case - with only the first element
    if (arr[0] <= k) dp[0][arr[0]] = true;

    // Step 4: Fill the DP table
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if (arr[ind] <= target) 
                take = dp[ind - 1][target - arr[ind]];
            
            dp[ind][target] = take || notTake;
        }
    }

    // Step 5: Final answer
    return dp[n - 1][k];
}
    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        for(int i=0 ; i<nums.size() ; i++)
            totalsum += nums[i];
        if(totalsum%2 == 1) return false;
    
        int target = totalsum/2;
        return subsetSumToK(nums.size(), target, nums);

        }
};