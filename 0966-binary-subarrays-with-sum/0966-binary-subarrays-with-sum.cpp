// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int left = 0;
//         int right = left+1;
//         int sum = 0;
//         int ans = 0;
//         while(left<right && right < nums.size() && left < nums.size()){
//             sum = sum+nums[right]+nums[left];
//             if(sum < goal){
//                 right++;
//                 sum+=nums[right];
//             }
//             else if(sum > goal){
//                 left++;
//                 sum-=nums[left];
//             }
//             else{
//                 ans++;
//                 right++;
//                 sum+=nums[right];
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int totalCount = 0;
        int currentSum = 0;
        // {prefix: number of occurrence}
        unordered_map<int, int> freq; // To store the frequency of prefix sums

        for (int num : nums) {
            currentSum += num;
            if (currentSum == goal){
                totalCount++;
            }

            // Check if there is any prefix sum that can be subtracted from the current sum to get the desired goal
            if (freq.find(currentSum - goal) != freq.end()){
                totalCount += freq[currentSum - goal];
            }

            freq[currentSum]++;
        }

        return totalCount;
    }
};
