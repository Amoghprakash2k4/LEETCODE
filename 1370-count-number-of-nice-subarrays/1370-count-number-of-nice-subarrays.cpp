class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int count = 0;
        int ans = 0;

        while (right < nums.size()) {
            // If current number is odd, reduce k
            if (nums[right] % 2 == 1) {
                k--;
            }

            // While we exceed the allowed odd numbers, move left forward
            while (k < 0) {
                if (nums[left] % 2 == 1) {
                    k++;
                }
                left++;
            }

            // All subarrays ending at 'right' and starting from [left, right] are valid
            ans += right - left + 1;

            right++;
        }

        return ans;
    }
};
