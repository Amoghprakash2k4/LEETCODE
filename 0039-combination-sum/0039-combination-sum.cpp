class Solution {
public:
    void backtrack(int idx, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if target == 0, we found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // If we run out of candidates or overshoot the target
        if (idx >= candidates.size() || target < 0) {
            return;
        }

        // Choice 1: take current candidate
        current.push_back(candidates[idx]);
        backtrack(idx, candidates, target - candidates[idx], current, result);
        current.pop_back();

        // Choice 2: skip current candidate, move to next
        backtrack(idx + 1, candidates, target, current, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, candidates, target, current, result);
        return result;
    }
};
