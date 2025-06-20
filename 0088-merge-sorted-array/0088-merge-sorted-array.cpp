class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m - 1;
        int q = n - 1;
        int p1 = m + n - 1;

        while (p >= 0 && q >= 0) {
            if (nums1[p] > nums2[q]) {
                nums1[p1] = nums1[p];
                p--;
            } else {
                nums1[p1] = nums2[q];
                q--;
            }
            p1--;
        }

        // If any elements are left in nums2
        while (q >= 0) {
            nums1[p1] = nums2[q];
            q--;
            p1--;
        }
    }
};
