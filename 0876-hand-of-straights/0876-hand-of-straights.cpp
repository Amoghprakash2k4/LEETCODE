class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int start = it->first;
            int count = it->second;

            if (count > 0) {
                // Try to build groups starting from 'start'
                for (int i = 0; i < groupSize; ++i) {
                    int card = start + i;
                    if (freq[card] < count) {
                        return false;
                    }
                    freq[card] -= count;
                }
            }
        }
        return true;
    }
};
