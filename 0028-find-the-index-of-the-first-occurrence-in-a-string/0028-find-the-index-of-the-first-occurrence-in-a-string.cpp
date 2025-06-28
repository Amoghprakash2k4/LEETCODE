class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int first = 0; 
        int count = 0;
        for(int i = 0; i < haystack.size(); i++) {
            if(haystack[i] == needle[count]) {
                if(count == 0) first = i;
                count++;
                if(count == needle.size()) return first;
            }
            else {
                if(count > 0) {
                    // go back to the character after first matched character
                    i = first;
                }
                count = 0;
            }
        }
        return -1;
    }
};
