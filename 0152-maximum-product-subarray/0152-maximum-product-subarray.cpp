class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPrd = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int prd = 1;
            for (int j = i; j < nums.size(); j++) {
                prd *= nums[j];
                maxPrd = max(maxPrd, prd);
            }
        }
        return maxPrd;
    }
};
