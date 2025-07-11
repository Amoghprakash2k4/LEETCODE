class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        // Min-heap to always get the smallest card
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto& p : count) {
            minHeap.push(p.first);
        }

        while (!minHeap.empty()) {
            int start = minHeap.top();
            minHeap.pop();

            if (count[start] == 0) continue; // Already used up

            int freq = count[start];
            for (int i = 0; i < groupSize; ++i) {
                int card = start + i;
                if (count[card] < freq) {
                    return false; // Not enough cards to form a group
                }
                count[card] -= freq;

                // Clean up heap if needed
                if (count[card] == 0 && card != start) {
                    // Remove empty entries for correctness
                    // (we don't remove from heap because heap only stores unique keys initially)
                    // But if you want to maintain a clean heap, you can rebuild the heap here.
                }
            }
        }
        return true;
    }
};
