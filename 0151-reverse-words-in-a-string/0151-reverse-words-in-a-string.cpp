class Solution {
public:
    string reverseWords(string s) {
        string result;
        int n = s.length();
        int i = n - 1;

        while (i >= 0) {
            // Skip trailing spaces
            while (i >= 0 && s[i] == ' ') i--;

            if (i < 0) break;

            int j = i;

            // Find the start of the word
            while (i >= 0 && s[i] != ' ') i--;

            // Extract the word
            string word = s.substr(i + 1, j - i);

            if (!result.empty()) result += ' ';
            result += word;
        }

        return result;
    }
};
