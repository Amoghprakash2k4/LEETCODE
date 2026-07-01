class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlength = 1;
        if(nums.size() == 0)
            return 0;
        
        sort(nums.begin(), nums.end());
        int localcount = 1;
        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i] == nums[i-1])
                continue;
            else if(nums[i] == nums[i-1] + 1)
                localcount++;

            else
                localcount = 1;

            maxlength = max(maxlength, localcount);

        }
        return maxlength;
    }
};