class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int curm = nums[0];
    int maxs = nums[0];

    for(int i=1 ; i<n ; i++){
        curm = max(nums[i], curm+nums[i]);
        maxs = max(maxs, curm);
    }
    return maxs;
    }
};