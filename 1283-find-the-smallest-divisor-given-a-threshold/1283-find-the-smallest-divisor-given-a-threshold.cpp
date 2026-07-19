class Solution {
public:
    int computeSum(vector<int>& nums, int divisor) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + divisor - 1) / divisor; // equivalent to ceil(num/divisor)
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int ans = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int currSum = computeSum(nums, mid);
            
            if (currSum <= threshold) {
                ans = mid;           // this could be the answer
                right = mid - 1;     // try smaller
            } else {
                left = mid + 1;      // try larger
            }
        }
        return ans;
    }
};
