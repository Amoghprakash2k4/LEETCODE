#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> merged;
        int i = 0, j = 0;

        // Merge the two sorted arrays
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i++]);
            } else {
                merged.push_back(nums2[j++]);
            }
        }

        // Append remaining elements
        while (i < m) merged.push_back(nums1[i++]);
        while (j < n) merged.push_back(nums2[j++]);

        int total = m + n;
        if (total % 2 == 1) {
            // Odd length, return middle element
            return merged[total / 2];
        } else {
            // Even length, return average of two middle elements
            return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
        }
    }
};
