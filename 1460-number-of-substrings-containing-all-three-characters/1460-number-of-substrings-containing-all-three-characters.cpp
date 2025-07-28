class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0, 0, 0};  // Count of 'a', 'b', and 'c'
        int res = 0;
        int left = 0;
        
        for (int right = 0; right < s.size(); ++right) {
            count[s[right] - 'a']++;
            
            // Move left pointer to smallest valid window
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                res += s.size() - right;  // All substrings from this point forward are valid
                count[s[left] - 'a']--;
                left++;
            }
        }
        
        return res;
    }
};
