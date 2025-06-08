class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int n= nums.size();
        // int counter=1;
        // for(int i=1; i<nums.size(); i++){
        //     if(nums[i]==nums[i-1]){
        //         counter++;
        //         if(counter > n/2){
        //             return nums[i];}
        //     }
        //     else{
        //         counter=1;
        //     }
        // }
        // return nums[0];


        // Boyer MOore voting algorithm
                int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};