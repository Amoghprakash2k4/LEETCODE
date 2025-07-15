class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse from the last digit backward
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            // Set current digit to 0 and continue carry
            digits[i] = 0;
        }
        
        // If all digits were 9, we need to add 1 at the front
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
