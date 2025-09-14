class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0; // no valid subarray
        int left = 0, sum = 0, ans = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum > goal) {
                sum -= nums[left];
                left++;
            }

            ans += (right - left + 1);
        }
        return ans;
    }
};
