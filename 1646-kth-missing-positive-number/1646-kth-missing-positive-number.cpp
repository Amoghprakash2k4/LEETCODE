class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missingCount = 0;
        int curr = 1; // Start checking from 1
        int i = 0;

        while (missingCount < k) {
            if (i < arr.size() && arr[i] == curr) {
                i++; // current number is present, move to next element in arr
            } else {
                missingCount++; // it's a missing number
                if (missingCount == k) return curr;
            }
            curr++;
        }

        return -1; // This should not be reached
    }
};
