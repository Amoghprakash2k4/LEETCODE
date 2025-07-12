class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    // unordered_map<int,int> freq;
    // for(int num : nums) {
    //     freq[num]++;
    // }

    // vector<pair<int,int>> freqVec(freq.begin(), freq.end());

    // sort(freqVec.begin(), freqVec.end(), [](auto& a, auto& b){
    //     return a.second > b.second; // sort by frequency descending
    // });

    // vector<int> result;
    // for(int i=0; i<k; i++) {
    //     result.push_back(freqVec[i].first);
    // }
    // return result;
    unordered_map<int,int> freq;
    for(int num : nums) {
        freq[num]++;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

    for(auto& [num, count] : freq) {
        minHeap.push({count, num});
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> result;
    while(!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}

};