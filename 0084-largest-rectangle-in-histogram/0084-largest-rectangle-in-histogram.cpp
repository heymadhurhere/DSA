class Solution {
public:
    // store the indices of next and prev smaller element
    vector<int> nextSmallerElement(vector<int>& arr, int n) {
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerElement(vector<int>& arr, int n) {
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 1)
            return heights[0];
        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);

        int area = INT_MIN;

        for (int i = 0; i < n; i++) {
            int l = heights[i];
            int left = 0, right = n;
            if (next[i] == -1) {
                right = n;
            }
            if (next[i] != -1) {
                right = next[i];
            }
            left = prev[i];
            int b = right - left - 1;
            area = max(area, l * b);
        }
        return area;
    }
};