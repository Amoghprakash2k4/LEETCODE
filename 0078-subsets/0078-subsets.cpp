#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(current);  // Reached the end, store current subset
            return;
        }
        
        // Not take the current element
        backtrack(index + 1, nums, current, result);
        
        // Take the current element
        current.push_back(nums[index]);
        backtrack(index + 1, nums, current, result);
        
        // Backtrack: remove the last added element
        current.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
};
