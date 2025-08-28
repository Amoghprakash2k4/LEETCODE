class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // // vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        // vector<int> curr(n+1,0);
        // vector<int> next(n+1,0);
        // for(int ind = n-1 ; ind >= 0 ; ind--){
        //     for(int prev= ind-1 ; prev >= -1 ; prev--){
        //         int len = 0+next[prev+1];

        //         if(prev == -1 || nums[ind] > nums[prev])
        //             len = max(len, 1+next[ind+1]);

        //         curr[prev+1]= len;
        //     }
        //     next = curr;
        // }
        // return next[0];



        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i=1; i<n ; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();

                temp[ind]=nums[i];
            }
        }
        return len;
    }
};