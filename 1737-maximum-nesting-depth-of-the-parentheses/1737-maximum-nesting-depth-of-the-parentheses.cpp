class Solution {
public:
    int maxDepth(string s) {
        int max = 0;
        int count = 0;
        for(int i=0 ; i<s.length() ;i++){
            if(s[i] == '('){
                count++;
                max = (max < count) ? count : max;

            }
            if(s[i] == ')'){
                count--;
            }
        }
        return max;
    }
};