class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        long long left=0,right=0,farthest=0;
        while(right <nums.size()-1){
            for(int i=left ; i<=right ; i++){
                farthest = max(farthest, (long long)i+nums[i]);
            }
            left = right+1;
            right = farthest;
            jumps++;
        }
        return jumps;
    }
};
