class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        int counter=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]){
                counter++;
                if(counter > n/2){
                    return nums[i];}
            }
            else{
                counter=1;
            }
        }
        return nums[0];
    }
};