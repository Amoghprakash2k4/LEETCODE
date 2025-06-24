class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        vector<int> count(256, 0);  // ASCII size

        for (int i = 0; i < s.length(); i++) {
            count[s[i]]++;
            count[t[i]]--;
        }

        for (int i = 0; i < 256; i++) {
            if (count[i] != 0) return false;
        }

        return true;
    }
};
