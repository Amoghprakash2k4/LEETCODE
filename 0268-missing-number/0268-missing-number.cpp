// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] != i) {
//                 return i;
//             }
//         }
//         return nums.size(); // If all numbers 0 to n-1 are present, return n
//     }
// };

        class Solution {
        public:
            int missingNumber(vector<int>& nums) {
                int n = nums.size();
                int total = n * (n + 1) / 2;  // Expected sum of 0 to n
                int sum = 0;
                for (int num : nums) {
                    sum += num;
                }
                return total - sum;  // The missing number
            }
        };
