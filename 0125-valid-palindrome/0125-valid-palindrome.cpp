class Solution {
public:
    bool isPalindrome(string s) {
        string valid="";
        for(char num: s){
            if(isalnum(num)){
                valid+=tolower(num);
            }
        }
        for(int i=0; i<valid.length() / 2; i++){
            if(valid[i] != valid[valid.length() - 1 -i]){
                    return 0;
            }
        }
        return true;
    }
};