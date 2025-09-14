class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        int count = 0, minlength = 1e9, startindex = -1;
        unordered_map<char, int> hash;

        // Count frequency of chars in t
        for (char c : t) {
            hash[c]++;
        }

        while (right < s.size()) {
            if (hash[s[right]] > 0) {
                count++;
            }
            hash[s[right]]--;

            // When all chars of t are matched
            while (count == t.size()) {
                if (right - left + 1 < minlength) {
                    minlength = right - left + 1;
                    startindex = left;
                }

                // Shrink window
                hash[s[left]]++;
                if (hash[s[left]] > 0) {
                    count--;
                }
                left++;
            }

            right++;
        }

        return startindex == -1 ? "" : s.substr(startindex, minlength);
    }
};
