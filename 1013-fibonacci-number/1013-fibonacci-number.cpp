class Solution {
public:
    // int dp(int n, vector<int>& dparr) {
    //     if (n <= 1) return n;

    //     if (dparr[n] != -1)
    //         return dparr[n];

    //     return dparr[n] = dp(n - 1, dparr) + dp(n - 2, dparr);
    // }

    int fib(int n) {
        // vector<int> dparr(n + 1, -1); // initialize with -1
    //     return dp(n, dparr);
    // }
    // ----------------
    // if(n<=1) return n;

    // dparr[0]=0;dparr[1]=1;
    // for(int i=2; i<=n; i++){
    //     dparr[i] = dparr[i-1]+dparr[i-2];
    // }
    // return dparr[n];
    // ---------------
    if (n <= 1) return n;
    int prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
    }
};

