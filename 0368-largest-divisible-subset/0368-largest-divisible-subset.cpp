#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        // Handle the edge case of an empty input vector.
        if (nums.empty()) {
            return {};
        }

        // 1. Sort the array. This is crucial as it allows us to build subsets
        // by only checking predecessors.
        std::sort(nums.begin(), nums.end());

        // 2. dp[i] will store the largest divisible subset ending with nums[i].
        std::vector<std::vector<int>> dp(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            // Find the longest preceding subset that nums[i] can extend.
            std::vector<int> longest_prefix;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j].size() > longest_prefix.size()) {
                    longest_prefix = dp[j];
                }
            }
            // Add the current number to the best prefix found.
            longest_prefix.push_back(nums[i]);
            dp[i] = longest_prefix;
        }

        // 3. Find and return the largest subset from all the generated ones.
        std::vector<int> result;
        for (const auto& subset : dp) {
            if (subset.size() > result.size()) {
                result = subset;
            }
        }
        return result;
    }
};