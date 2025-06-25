class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long result = 0;

        // Skip leading spaces
        while (i < s.length() && s[i] == ' ') i++;

        // Check sign
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert digits
        while (i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Clamp to 32-bit signed integer range
            if (result * sign >= INT_MAX) return INT_MAX;
            if (result * sign <= INT_MIN) return INT_MIN;

            i++;
        }

        return result * sign;
    }
};
