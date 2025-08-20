class Solution {
public:
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    vector<bool> prev(k+1,0);
    // , curr(k+1,0);
    
    prev[0]= true;
    // curr[0] =
     if (arr[0] <= k) prev[arr[0]] = true;

    // Step 3: Base Case - with only the first element
    // if (arr[0] <= k) dp[0][arr[0]] = true;

    // Step 4: Fill the DP table
    for (int ind = 1; ind < n; ind++) {
        // curr[0] = true;
        prev[0]= true;
        for (int target = k; target >= 0; target--) {
            bool notTake = prev[target];
            bool take = false;
            if (arr[ind] <= target) 
                take =prev[target - arr[ind]];
            
            prev[target] = take || notTake;
        }
        // prev = curr;
    }

    // Step 5: Final answer
    return prev[k];
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