class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    //     int maxlength = 0, left = 0, count = 0;

    //     for (int i = 0; i < nums.size(); i++) {
    //         if (nums[i] == 0) {
    //             count++;
    //         }

    //         while (count > k) {
    //             if (nums[left] == 0) {
    //                 count--;
    //             }
    //             left++;
    //         }

    //         maxlength = max(maxlength, i - left + 1);
    //     }

    //     return maxlength;
    // }

    int maxlength =0, left=0, count=0;
    for(int i=0 ; i<nums.size();i++){
        if(nums[i] == 0){
            count++;
        }
        while(count>k){
            if(nums[left] == 0){
                count--;
            }
            left++;
        }
        maxlength = max(maxlength, i-left+1);
    }
    return maxlength;

    }

};
