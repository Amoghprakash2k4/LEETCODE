class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MAX && divisor == -1) {
            return INT_MIN+1;
        }
        // if(divisor == -1) return -dividend;
        // Work with long long to handle INT_MIN safely
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long result = 0;

        // Keep subtracting divisor until dividend is smaller
        while (a >= b) {
            a -= b;
            result++;
        }

        // Apply sign
        if ((dividend < 0) ^ (divisor < 0)) {
            result = -result;
        }

        return (int)result;
    }
};
