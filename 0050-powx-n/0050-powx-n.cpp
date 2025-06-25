class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;  // Convert to long long to handle INT_MIN
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1;
        
        while (N) {
            if (N % 2 == 1) result *= x;
            x *= x;
            N /= 2;
        }
        return result;
    }
};
