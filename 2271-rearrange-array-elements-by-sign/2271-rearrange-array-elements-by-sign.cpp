class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negetive;
        vector<int> result;
        for(int i=0; i <nums.size(); i++){
            if(nums[i] > 0){
                positive.push_back(nums[i]);
            }
            else if(nums[i] < 0){
                negetive.push_back(nums[i]);
            }
        }
        for(int i=0;i <nums.size()/2; i++){
            result.push_back(positive[i]);
            result.push_back(negetive[i]);
        }
        return result;
    }
};