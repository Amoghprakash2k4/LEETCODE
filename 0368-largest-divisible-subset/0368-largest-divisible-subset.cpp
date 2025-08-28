class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};

        sort(nums.begin(), nums.end()); // Step 1: sort the array

        vector<int> dp(n, 1), parent(n); // dp[i] = size of subset ending at i
        int maxi = 1, lastIndex = 0;

        // Step 2: DP to find longest divisible subset
        for(int i = 0; i < n; i++) {
            parent[i] = i; // initialize parent as itself
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        // Step 3: Reconstruct subset
        vector<int> result;
        result.push_back(nums[lastIndex]);
        while(parent[lastIndex] != lastIndex) {
            lastIndex = parent[lastIndex];
            result.push_back(nums[lastIndex]);
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
