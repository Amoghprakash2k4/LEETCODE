class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        sort(nums.begin(), nums.end());
        
        vector<int> dp(n, 1);         // dp[i] = length of LDS ending at i
        vector<int> parent(n, -1);    // to reconstruct path
        int maxLen = 1, lastIndex = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }
        
        // reconstruct subset
        vector<int> ans;
        while (lastIndex != -1) {
            ans.push_back(nums[lastIndex]);
            lastIndex = parent[lastIndex];
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
