class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int goal) {
        return f(nums, goal) - f(nums, goal-1);

    }

    int f(vector<int>& nums, int goal){
        int left=0 , count =0, right=0;
        int sum=0;

        while(right <nums.size()){
            sum+=(nums[right] % 2);
            while(sum > goal && left<=right){
                sum-=(nums[left] % 2);
                left++;
            }
            count+= right-left+1;
            right++;
        }
        return count;
    }
    
};