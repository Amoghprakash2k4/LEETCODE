class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<pair<int, int>> vec;

        for (auto it : freq) {
            vec.push_back({it.second, it.first});
        }

        sort(vec.begin(), vec.end(), [](pair<int,int>& a, pair<int,int>& b) {
            return a.first > b.first;
        });

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(vec[i].second);
        }

        return ans;
    }
};