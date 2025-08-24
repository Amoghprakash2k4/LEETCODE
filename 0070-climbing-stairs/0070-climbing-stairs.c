int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }
    
    int prev1 = 1;  // dp[i-1] (the number of ways to reach step i-1)
    int prev2 = 1;  // dp[i-2] (the number of ways to reach step i-2)
    int current;    // dp[i] (the number of ways to reach step i)
    
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;  // dp[i] = dp[i-1] + dp[i-2]
        prev2 = prev1;            // Update dp[i-2] to dp[i-1]
        prev1 = current;          // Update dp[i-1] to dp[i]
    }
    
    return current;
}