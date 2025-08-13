class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false; // Negative numbers and 0 are not powers of three
        
        while (n % 3 == 0) { // Keep dividing by 3 while divisible
            n /= 3;
        }
        
        return n == 1; // Only powers of three reduce to 1
    }
};
