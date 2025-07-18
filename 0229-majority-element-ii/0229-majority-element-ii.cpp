class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        int n = nums.size();
        int count = 1;
        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i] == nums[i-1]){
                count++;
            }
            else{
                if(count > n/3){
                    result.push_back(nums[i-1]);
                }
                count = 1;
            }
        }
        if(count > n/3){
            result.push_back(nums[n-1]);
        }
        return result;
    }
};