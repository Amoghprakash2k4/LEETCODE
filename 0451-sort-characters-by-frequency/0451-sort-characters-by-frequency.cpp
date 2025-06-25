class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Convert to vector of pairs to sort
        vector<pair<char, int>> freqVec(freq.begin(), freq.end());

        // Sort by frequency descending
        sort(freqVec.begin(), freqVec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Build result string
        string result;
        for (auto &p : freqVec) {
            result += string(p.second, p.first);
        }

        return result;
    }
};
