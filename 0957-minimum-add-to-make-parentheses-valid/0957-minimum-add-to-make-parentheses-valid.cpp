class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;       // count of unmatched '('
        int insertions = 0; // count of insertions needed for ')'

        for(char c : s){
            if(c == '(') {
                open++; // open a new bracket
            } else if(c == ')') {
                if(open > 0)
                    open--; // match with a previous '('
                else
                    insertions++; // need to insert a '(' to match this ')'
            }
        }

        // total insertions = unmatched '(' + unmatched ')'
        return insertions + open;
    }
};
