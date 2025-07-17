class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // Sort greed factors
        sort(s.begin(), s.end()); // Sort cookie sizes 

        int child = 0, cookie = 0;
        while (child < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[child]) {
                // Cookie can satisfy the child
                child++;
            }
            cookie++; // Move to next cookie
        }
        return child; // Number of content children
    }
};
