class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char digit : num) {
            // While top of stack > current digit, pop (greedy)
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        // If k > 0, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build the result from stack (reverse order)
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());

        // Remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0') i++;
        result = result.substr(i);

        return result.empty() ? "0" : result;
    }
};
