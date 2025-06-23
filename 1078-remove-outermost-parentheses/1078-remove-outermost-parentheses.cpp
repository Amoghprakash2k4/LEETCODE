class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int count = 0;    // Nesting depth
        int start = 0;    // Start index of current primitive

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                count++;
            } else {
                count--;
            }

            if (count == 0) {
              
                result += s.substr(start + 1, i - start - 1);
                start = i + 1; 
            }
        }

        return result;
    }
};
