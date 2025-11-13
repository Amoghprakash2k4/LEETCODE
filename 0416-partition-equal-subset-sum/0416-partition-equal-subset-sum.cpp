class Solution {
public:
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));

    for(int i=0 ; i<n ; i++){
        dp[i][0] = true;
    }

    if(arr[0] <= k) 
        dp[0][arr[0]] = true;

    for(int ind = 1 ; ind <arr.size() ; ind++){
        for(int target = 1 ; target<=k ; target++){
            bool nottake = dp[ind-1][target];

            bool take = false;
            if(arr[ind] <= target)
                take = dp[ind-1][target - arr[ind]];

            dp[ind][target] = take || nottake;

        }
        
    }
    return dp[n-1][k];
    // // vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    // vector<bool> prev(k+1,0);
    // // , curr(k+1,0);
    
    // prev[0]= true;
    // // curr[0] =
    //  if (arr[0] <= k) prev[arr[0]] = true;

    // // Step 3: Base Case - with only the first element
    // // if (arr[0] <= k) dp[0][arr[0]] = true;

    // // Step 4: Fill the DP table
    // for (int ind = 1; ind < n; ind++) {
    //     // curr[0] = true;
    //     prev[0]= true;
    //     for (int target = k; target >= 0; target--) {
    //         bool notTake = prev[target];
    //         bool take = false;
    //         if (arr[ind] <= target) 
    //             take =prev[target - arr[ind]];
            
    //         prev[target] = take || notTake;
    //     }
    //     // prev = curr;
    // }

    // // Step 5: Final answer
    // return prev[k];

    // vector<bool> prev(k+1,false);
    // prev[0] = true;
    // if(arr[0] <= k) prev[arr[0]] = true;
    // for(int i=1 ; i<n ; i++){
    //     prev[0]= true;
    //     for(int target=k ; target>=0 ; target--){
    //         bool nottaken = prev[target];
    //         bool taken = false;
    //         if(arr[i] <= target)
    //             taken = prev[target - arr[i]];

    //         prev[target] = taken || nottaken;
    //     }
    // }
    // return prev[k];
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


// 2DDDD


// #include <vector>
// using namespace std;

// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     // Step 1: Create a DP table of size n x (k+1)
//     vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

//     // Step 2: Base case — target 0 is always achievable (by taking no elements)
//     for (int i = 0; i < n; i++)
//         dp[i][0] = true;

//     // Step 3: Base case — only first element
//     if (arr[0] <= k)
//         dp[0][arr[0]] = true;

//     // Step 4: Fill the DP table
//     for (int ind = 1; ind < n; ind++) {
//         for (int target = 1; target <= k; target++) {
//             bool notTake = dp[ind - 1][target]; // skip current element

//             bool take = false;
//             if (arr[ind] <= target)
//                 take = dp[ind - 1][target - arr[ind]]; // include current element

//             dp[ind][target] = take || notTake;
//         }
//     }

//     // Step 5: Final answer — can we form sum k using all n elements?
//     return dp[n - 1][k];
// }
