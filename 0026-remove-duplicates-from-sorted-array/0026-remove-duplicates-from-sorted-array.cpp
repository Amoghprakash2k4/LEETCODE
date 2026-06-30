class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    //     if (nums.size() == 0) return 0;

    //     int i = 0;  // pointer for the position of last unique element

    //     for (int j = 1; j < nums.size(); j++) {
    //         if (nums[j] != nums[i]) {
    //             i++;                  // move to the next unique position
    //             nums[i] = nums[j];    // overwrite duplicate with unique
    //         }
    //     }

    //     return i + 1;  // the length of unique elements
    // }

    int n = nums.size();
    int i=0 ;
    for(int j=1 ; j<n ; j++){
        if(nums[i] != nums[j]){
            i++;
            nums[i] = nums[j];
        }
    }
    return i+1;
    }
};
