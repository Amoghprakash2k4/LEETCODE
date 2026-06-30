class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    //    int j=0; //place where 1st 0 is found
    //    for(int i=0; i<nums.size() ; i++){
    //         if(nums[i] != 0){
    //             nums[j] = nums[i];
    //             j++;
    //         }
    //    }
    //    for(int i=j; i<nums.size();i++){
    //         nums[i]=0;
    //    }
    // }


    int n= nums.size();
    int j=0 ;
    for(int i=0 ; i<n ; i++){
        if(nums[i] !=0){
            nums[j] = nums[i];
            j++;
        }
    }
    while(j<n){
        nums[j] = 0;
        j++;
    }
    }
};