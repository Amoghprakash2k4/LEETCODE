class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st; // stores indices

        // Loop twice to handle circularity
        for (int i = 0; i < 2 * n; ++i) {
            int num = nums[i % n];
            // Compare with elements in stack
            while (!st.empty() && nums[st.top()] < num) {
                res[st.top()] = num;
                st.pop();
            }
            if (i < n) {
                st.push(i);
            }
        }
        return res;
    }
};
