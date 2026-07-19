#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int x = nums1.size();
        int y = nums2.size();
        int left=0, right=x;

        while(left <= right){
            int px = left+(right-left)/2;
            int py = (x+y+1)/2 - px;

            int maxleftx = (px == 0) ? INT_MIN : nums1[px-1];
            int minrightx = (px == x) ? INT_MAX : nums1[px];

            int maxlefty = (py == 0) ? INT_MIN : nums2[py-1];
            int minrighty = (py == y) ? INT_MAX : nums2[py];

            if(maxleftx <= minrighty && maxlefty <= minrightx){
                if((x+y)%2 == 0)
                return (max(maxleftx, maxlefty) + min(minrightx, minrighty)) / 2.0;
                else
                    return max(maxleftx, maxlefty);
                
            }
            else if(maxleftx > minrighty)
                right = px-1;
            else 
                left = px+1;

        }
        return 0.0;

    }
};
