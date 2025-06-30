class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int a : asteroids) {
            bool alive = true;
            while (alive && !st.empty() && st.top() > 0 && a < 0) {
                if (abs(st.top()) < abs(a)) {
                    // Top asteroid explodes
                    st.pop();
                } else if (abs(st.top()) == abs(a)) {
                    // Both explode
                    st.pop();
                    alive = false;
                } else {
                    // Current asteroid explodes
                    alive = false;
                }
            }
            if (alive) {
                st.push(a);
            }
        }

        // Convert stack to vector
        vector<int> res(st.size());
        for (int i = res.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};
