/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int peak = findpeak(mountainArr, n);

        int index = binarysearch(mountainArr, target, 0, peak, true);
        if(index != -1) return index;

        return binarysearch(mountainArr, target, peak, n, false);
    }

    int findpeak(MountainArray &mountainArr, int size){
        int left = 0;
        int right = size-1;
        while(left < right){
            int mid = left + (right-left)/2;

            if(mountainArr.get(mid) < mountainArr.get(mid+1))
                left = mid+1;
            else
                right = mid;
        }

        return left;
    }

    int binarysearch(MountainArray &mountainArr, int target, int peak, int size, bool ascending){
        int left = peak, right = size-1;
        while(left <= right)
        {
            int mid = left +(right-left)/2;
            int value = mountainArr.get(mid);
            if(value == target) return mid;
        
            if(ascending){
            if(value < target) left = mid+1;
            else right = mid-1;
        }
        else{
            if(value < target) right = mid-1;
            else left = mid+1;
        }
        }
        return -1;


    }

};