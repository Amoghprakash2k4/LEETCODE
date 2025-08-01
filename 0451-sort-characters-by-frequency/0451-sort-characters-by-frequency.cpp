class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        vector<pair<char, int>> freqVec(freq.begin(), freq.end());

        
        sort(freqVec.begin(), freqVec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string result;
        for (auto &p : freqVec) {
            result += string(p.second, p.first);
        }

        return result;
    }
};
