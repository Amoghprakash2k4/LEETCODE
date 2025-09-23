class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;
        st.push(nums[n-1]);
        for(int ind=2*n-1 ; ind >=0 ; ind--){
            int i = ind%n;
            while( !st.empty() && st.top() <= nums[i] ) st.pop();

            if(!st.empty()) nge[i] = st.top();
            st.push(nums[i]);
        }
        return nge;
    }
};
