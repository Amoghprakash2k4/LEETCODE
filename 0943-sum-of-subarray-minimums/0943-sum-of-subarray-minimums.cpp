class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> ple(n); // Previous Less Element indices
        vector<int> nle(n); // Next Less Element indices
        stack<int> st;

        // Previous Less
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack for reuse
        while (!st.empty()) st.pop();

        // Next Less
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Compute result
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            sum = (sum + arr[i] * left * right) % MOD;
        }

        return (int)sum;
    }
};
