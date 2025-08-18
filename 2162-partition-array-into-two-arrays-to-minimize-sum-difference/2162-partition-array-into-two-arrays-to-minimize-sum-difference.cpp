// class Solution {
// public:
//     int minimumDifference(vector<int>& nums) {
//         int k=0;
//         for(int i = 0 ; i < nums.size(); i++) k+=nums[i];

//         int n = nums.size();

//         vector<bool> prev(k+1, 0), curr(k+1, 0);

//         curr[0] = prev[0] = true;
//         if(nums[0] <= k ) prev[nums[0]] = true;

//         for(int ind=1 ; ind<n ; ind++){
//             fill(curr.begin(), curr.end(), false); // Reset the table!
//             curr[0]= true;
//             for(int target=0 ; target <= k ; target++ ){
//                 bool nottaken = prev[target];
//                 bool taken = false;
//                 if(nums[ind] <= target)
//                     taken = prev[target - nums[ind]];

//                 curr[target] = taken || nottaken;

//             }
//             prev = curr;
//         }

//         int mini = 1e9;
//         for(int s1=0 ; s1<=k/2 ; s1++){
//             if(prev[s1] == true){
//                 mini = min(mini, abs((k-s1)-s1));

//             }
//         }
//         return mini;

//     }
// };


class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int half = n / 2;

        // left and right halves
        vector<int> left(nums.begin(), nums.begin() + half);
        vector<int> right(nums.begin() + half, nums.end());

        // subset sums grouped by subset size
        auto getSums = [](vector<int>& arr) {
            int m = arr.size();
            vector<vector<long long>> res(m+1);
            for (int mask = 0; mask < (1 << m); mask++) {
                long long sum = 0;
                int cnt = 0;
                for (int i = 0; i < m; i++) {
                    if (mask & (1 << i)) {
                        sum += arr[i];
                        cnt++;
                    }
                }
                res[cnt].push_back(sum);
            }
            for (auto& v : res) sort(v.begin(), v.end());
            return res;
        };

        auto leftSums = getSums(left);
        auto rightSums = getSums(right);

        long long ans = LLONG_MAX;
        int n2 = n / 2;

        // try picking k elements from left and (n2-k) from right
        for (int k = 0; k <= half; k++) {
            int need = n2 - k;
            for (long long s1 : leftSums[k]) {
                long long target = total / 2 - s1;
                auto& vec = rightSums[need];
                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    long long s2 = *it;
                    long long chosen = s1 + s2;
                    ans = min(ans, llabs(total - 2 * chosen));
                }
                if (it != vec.begin()) {
                    --it;
                    long long s2 = *it;
                    long long chosen = s1 + s2;
                    ans = min(ans, llabs(total - 2 * chosen));
                }
            }
        }

        return (int)ans;
    }
};
