#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int i=0;
        for(int num : nums){
            int comp = target - num;
            if(mp.find(comp) != mp.end()){
                return{mp[comp], i};
            }
            mp[num] = i;
            i++;
        }
        return {};
    }
};
