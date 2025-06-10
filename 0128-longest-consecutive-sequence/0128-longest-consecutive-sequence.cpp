class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int maxlength =1;
        int locallength=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            else if(nums[i] == nums[i-1] +1){
                locallength++;
            }
            else{
                locallength=1;
            }
            maxlength = max(maxlength, locallength);
        }
        return maxlength;
    }
};