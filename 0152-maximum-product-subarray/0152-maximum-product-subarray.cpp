// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int maxPrd = nums[0];
//             int prd = 1;
//             for (int j = 0; j < nums.size(); j++) {
//                 prd *= nums[j];
//                 maxPrd = max(maxPrd, max(prd, nums[j]));

            
//         }
//         return maxPrd;
//     }
// };


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPrd = nums[0];
        int prd = 1;

        // Forward pass
        for (int i = 0; i < nums.size(); i++) {
            prd *= nums[i];
            maxPrd = max(maxPrd, prd);
            if (nums[i] == 0) prd = 1;
        }

        prd = 1;

        // Backward pass
        for (int i = nums.size() - 1; i >= 0; i--) {
            prd *= nums[i];
            maxPrd = max(maxPrd, prd);
            if (nums[i] == 0) prd = 1;
        }

        return maxPrd;
    }
};
