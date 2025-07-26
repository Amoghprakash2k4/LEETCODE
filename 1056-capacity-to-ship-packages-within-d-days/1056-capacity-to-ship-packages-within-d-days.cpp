class Solution {
public:
    // Helper function to check if it is possible to ship within 'days' using capacity 'cap'
    bool canShip(vector<int>& weights, int days, int cap) {
        int d = 1, total = 0;
        for (int w : weights) {
            if (total + w > cap) {
                d++;
                total = 0;
            }
            total += w;
        }
        return d <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()); // min possible capacity
        int right = accumulate(weights.begin(), weights.end(), 0); // max possible capacity
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, days, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
