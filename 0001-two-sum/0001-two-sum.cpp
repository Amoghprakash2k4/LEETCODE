#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // for (int i = 0; i < nums.size() - 1; i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         if (nums[i] + nums[j] == target) {
        //             return {i, j};  // Return as a vector
        //         }
        //     }
        // }
        // return {};  // Return empty vector if no solution found

        unordered_map<int,int> list;
        for(int i=0; i<nums.size(); i++){
            int complinment= target-nums[i];
            if(list.find(complinment) != list.end()){
                return {list[complinment], i};
            }
            list[nums[i]] = i;
        }
        return {};
    }
};
