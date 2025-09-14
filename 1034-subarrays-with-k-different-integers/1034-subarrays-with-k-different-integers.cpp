class Solution {
public:

    int f(vector<int>& nums, int goal){
        int left=0, count=0, right=0;
        unordered_map<int,int> map;

        while(right <nums.size()){
            map[nums[right]]++;

            
            while(map.size() > goal){
                map[nums[left]]--;
                if(map[nums[left]] == 0 ) 
                    map.erase(nums[left]);
                left++;
            }
            count += (right - left + 1);
            right++;
            
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};