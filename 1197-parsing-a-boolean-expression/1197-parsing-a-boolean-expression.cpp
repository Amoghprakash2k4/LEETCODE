class Solution {
public:
    bool parseBoolExpr(string expression) {
        return eval(expression, 0, expression.size()-1);
    }

    bool eval(string &s, int l, int r) {
        if(l == r) return s[l] == 't';  // single char: 't' or 'f'
        
        char op = s[l];
        if(op == '!') {
            return !eval(s, l+2, r-1);  // inside ( )
        } else if(op == '&' || op == '|') {
            bool result = (op == '&');  // identity for AND = true, for OR = false
            int start = l+2;  // after "op("
            int depth = 0;
            for(int i = start; i < r; i++) {
                if(s[i] == '(') depth++;
                if(s[i] == ')') depth--;
                if(s[i] == ',' && depth == 0) {
                    bool val = eval(s, start, i-1);
                    if(op == '&') result &= val;
                    else result |= val;
                    start = i+1;
                }
            }
            // last argument
            bool val = eval(s, start, r-1);
            if(op == '&') result &= val;
            else result |= val;
            return result;
        }
        return false; // shouldn't reach
    }
};
