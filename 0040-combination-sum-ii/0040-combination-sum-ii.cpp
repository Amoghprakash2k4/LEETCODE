class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end()); // Step 1: sort
        backtrack(candidates, target, 0, current, result);
        return result;
    }

    void backtrack(vector<int>& candidates, int target, int start, 
                   vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // Stop if number exceeds remaining target
            if (candidates[i] > target) break;

            // Choose the number
            current.push_back(candidates[i]);

            // Move to next index (each element used only once)
            backtrack(candidates, target - candidates[i], i + 1, current, result);

            // Backtrack
            current.pop_back();
        }
    }
};
