class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mapper;
        stack<int> st;

        for( int c:nums2){
            while(!st.empty() && c > st.top()){
                mapper[st.top()] = c;
                st.pop();
            }
            st.push(c);
        }
        while (!st.empty()) {
            mapper[st.top()] = -1;
            st.pop();
        }
        vector<int> result;
        for (int num : nums1) {
            result.push_back(mapper[num]);
        }

        return result;
    }
};