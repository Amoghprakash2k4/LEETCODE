void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = m - 1; // Pointer to the last element in the part of nums1 to merge
    int p2 = n - 1; // Pointer to the last element in nums2
    int p = m + n - 1; // Pointer to the last position in nums1 where the merged elements will be placed
    
    // Merge in reverse order
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }

    // If there are remaining elements in nums2, copy them
    while (p2 >= 0) {
        nums1[p] = nums2[p2];
        p2--;
        p--;
    }
}