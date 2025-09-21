#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current); // store every subset
        
        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1]) continue;
            
            current.push_back(nums[i]);            // take nums[i]
            backtrack(i + 1, nums, current, result); // recurse
            current.pop_back();                    // backtrack
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort to handle duplicates
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
};
