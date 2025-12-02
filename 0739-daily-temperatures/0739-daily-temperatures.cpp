class Solution {
public:
    // next greater element index
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> nge(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            if (nge[i] == -1)
                nge[i] = 0;
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (nge[i] == 0)
                ans[i] = 0;
            else {
                ans[i] = nge[i] - i;
            }
        }
        return ans;
    }
};