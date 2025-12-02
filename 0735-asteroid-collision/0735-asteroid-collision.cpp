class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        int i = 0;

        while (i < n) {
            if (!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                if (st.top() == abs(asteroids[i])) {
                    st.pop();
                    i++;
                } else if (st.top() > abs(asteroids[i])) {
                    i++;
                } else if (st.top() < abs(asteroids[i])) {
                    st.pop();
                }
            } else {
                st.push(asteroids[i]);
                i++;
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};