class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;

        while (i < n && nums[i] != target) i++;
        if (i == n) return {-1, -1};  
        
        int j = i;
        while (j < n && nums[j] == target) j++;

        return {i, j - 1};  // j is one past the last index
    }
};
