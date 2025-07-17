class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0, farthest = 0;

        while (i <= farthest) {
            farthest = max(farthest, i + nums[i]);
            if (farthest >= n - 1) return true;
            i++;
        }

        return false;
    }
};
