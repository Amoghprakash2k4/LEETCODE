class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow: INT_MIN / -1 would overflow to INT_MAX+1
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Convert both numbers to long long to handle abs safely
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        long long ans = 0;

        // Keep subtracting divisor multiples from dividend
        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1;

            // Double temp until it is just less than dvd
            while ((temp << 1) <= dvd) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;        // subtract the largest found multiple
            ans += multiple;    // add that multiple to answer
        }

        // Apply sign
        if ((dividend < 0) ^ (divisor < 0)) { // XOR: true if only one is negative
            ans = -ans;
        }

        return (int)ans;
    }
};
