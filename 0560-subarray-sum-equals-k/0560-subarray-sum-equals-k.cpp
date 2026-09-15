class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    //     unordered_map<int, int> map;
    //     int count =0 ;
    //     map[0] = 1;
    //     int sum = 0;

    //     for(int i=0 ; i<nums.size() ; i++){
    //         sum += nums[i];
    //         int remove = sum - k;
    //         count += map[remove];
    //         map[sum]++;
    //     }
    //     return count;
    // }

    unordered_map<int,int> map;
    int sum = 0;
    int count = 0;
    map[0] = 1;

    for(int num : nums){
        sum += num;
        int remove = sum - k;
        count += map[remove];
        map[sum]++;
    }
    return count;
    }
};
