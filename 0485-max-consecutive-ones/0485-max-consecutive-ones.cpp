class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int currentMaxCount = 0;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            if(nums[i] == 1){
                currentMaxCount++;
                maxCount = max(maxCount, currentMaxCount);
            }
            else
            currentMaxCount = 0;
        }
        return maxCount;
    }
};
