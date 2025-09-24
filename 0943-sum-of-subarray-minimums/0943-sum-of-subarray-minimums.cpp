
class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int mod = 1e9 + 7, n = nums.size();
        vector<int> left(n), right(n);
        stack<int> s1, s2;
        for (int i = 0; i < n; ++i) {
            while (!s1.empty() && nums[s1.top()] > nums[i]) s1.pop();
            left[i] = s1.empty() ? -1 : s1.top();
            s1.push(i);
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!s2.empty() && nums[s2.top()] >= nums[i]) s2.pop();
            right[i] = s2.empty() ? n : s2.top();
            s2.push(i);
        }
        long res = 0;
        for (int i = 0; i < n; ++i) {
            long l = i - left[i], r = right[i] - i;
            res = (res + nums[i] * l * r) % mod;
        }
        return res;
    }
};
