class Solution {
public:
    int dp(int n, vector<int>& dparr) {
        if (n <= 1) return n;

        if (dparr[n] != -1)
            return dparr[n];

        return dparr[n] = dp(n - 1, dparr) + dp(n - 2, dparr);
    }

    int fib(int n) {
        vector<int> dparr(n + 1, -1); // initialize with -1
        return dp(n, dparr);
    }
};

