class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;

        // For min contribution
        stack<int> st;
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                int j = st.top(); st.pop();
                int k = st.empty() ? -1 : st.top();
                res -= (long long)nums[j] * (i - j) * (j - k);
            }
            st.push(i);
        }

        // For max contribution
        while (!st.empty()) st.pop();  // clear stack
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[st.top()] < nums[i])) {
                int j = st.top(); st.pop();
                int k = st.empty() ? -1 : st.top();
                res += (long long)nums[j] * (i - j) * (j - k);
            }
            st.push(i);
        }

        return res;
    }
};
