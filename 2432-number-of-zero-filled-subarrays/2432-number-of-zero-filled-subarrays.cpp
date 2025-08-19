class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        long long count = 0;

        for (int num : nums) {
            if (num == 0) {
                count++;          // extend current zero streak
                result += count;  // add all subarrays ending here
            } else {
                count = 0;        // reset streak
            }
        }

        return result;
    }
};
