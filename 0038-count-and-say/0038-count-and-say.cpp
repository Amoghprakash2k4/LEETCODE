class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string prev = countAndSay(n - 1);  // get the sequence for n-1
        string result = "";
        
        int count = 1;  
        for (int i = 1; i <= prev.size(); i++) {
            if (i < prev.size() && prev[i] == prev[i - 1]) {
                count++;  // count same consecutive digits
            } else {
                result += to_string(count) + prev[i - 1];  // add "count + digit"
                count = 1;  // reset counter
            }
        }
        
        return result;
    }
};
