class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> freq;
        freq[0] = 1; // base case: empty prefix
        int sum = 0, ans = 0;

        for(int x : nums) {
            sum += x;  
            if(freq.count(sum - goal)) {
                ans += freq[sum - goal];
            }
            freq[sum]++;
        }

        return ans;
    }
};
