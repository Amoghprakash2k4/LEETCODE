class Solution {
public:
    long long minsum(vector<int>& arr) {
        int n = arr.size();
        vector<int> ple(n), nle(n);
        stack<int> st;

        // Previous Less
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Less
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            sum += 1LL * arr[i] * left * right;
        }
        return sum;
    }

    long long maxsum(vector<int>& arr) {
        int n = arr.size();
        vector<int> pge(n), nge(n); // Previous Greater, Next Greater
        stack<int> st;

        // Previous Greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            sum += 1LL * arr[i] * left * right;
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return maxsum(nums) - minsum(nums);
    }
};
