class Solution {
public:
    int uniquePaths(int m, int n) {
        // We want to compute C(m+n-2, m-1)
        long long res = 1;
        int N = m + n - 2;
        int k = min(m - 1, n - 1); // smaller of the two to reduce computations
        for (int i = 1; i <= k; ++i) {
            res = res * (N - k + i) / i;
        }
        return (int)res;
    }
};
