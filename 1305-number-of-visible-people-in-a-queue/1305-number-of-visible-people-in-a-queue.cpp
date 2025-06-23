class Solution {
public:
    // vector<int> canSeePersonsCount(vector<int>& heights) {
    //     int n = heights.size();
    //     vector<int> ans(n);
    //     for (int i = 0; i < n - 1; i++) {
    //         stack<int> st;
    //         st.push(heights[i + 1]);
    //         int cnt = 1;
    //         for (int j = i + 2; j < n; j++) {
    //             if (heights[j] > st.top() && st.top() < heights[i]) {
    //                 st.push(heights[j]);
    //                 cnt = st.size();
    //             }
    //         }
    //         ans[i] = cnt;
    //     }
    //     ans[n - 1] = 0;
    //     return ans;
    // }
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < heights[i]) {
                ans[i]++;
                st.pop();
            }
            if (!st.empty()) ans[i]++;
            st.push(heights[i]);
        }
        return ans;
    }
};