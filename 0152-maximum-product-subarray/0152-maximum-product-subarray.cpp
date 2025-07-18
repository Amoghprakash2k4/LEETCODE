class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPrd = nums[0];
        int prd = 1;

        for (int j = 0; j < nums.size(); j++) {
            prd *= nums[j];
            maxPrd = max(maxPrd, prd);
            if (prd == 0) prd = 1; // reset on zero
        }

        prd = 1;
        for (int j = nums.size() - 1; j >= 0; j--) {
            prd *= nums[j];
            maxPrd = max(maxPrd, prd);
            if (prd == 0) prd = 1; // reset on zero
        }

        return maxPrd;
    }
};



