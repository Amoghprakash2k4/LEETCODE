class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        
        unordered_map<char, int> charIndex;
        int maxLength = 0, left = 0;

        for (int i = 0; i < s.length(); i++) {
            if (charIndex.find(s[i]) != charIndex.end()) {
                left = max(left, charIndex[s[i]] + 1);
            }

            charIndex[s[i]] = i;
            maxLength = max(maxLength, i - left + 1);
        }

        return maxLength;
    }
};