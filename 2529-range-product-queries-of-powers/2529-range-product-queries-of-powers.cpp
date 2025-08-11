class Solution {
public:
    const int MOD = 1e9 + 7;
    
    long long modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // Step 1: extract powers of two from n
        vector<int> powers;
        for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) powers.push_back(1 << i);
        }
        
        // Step 2: prefix product
        vector<long long> prefix(powers.size() + 1, 1);
        for (int i = 0; i < powers.size(); i++) {
            prefix[i + 1] = (prefix[i] * powers[i]) % MOD;
        }
        
        // Step 3: answer queries
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long prod = (prefix[r + 1] * modPow(prefix[l], MOD - 2)) % MOD;
            ans.push_back(prod);
        }
        
        return ans;
    }
};
