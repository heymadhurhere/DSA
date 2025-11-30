class Solution {
public:
    vector<pair<int, int>> prevGreaterEle(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> ans(n, {LLONG_MAX, -1}); // {value, index}
        stack<int> st;                                  // will store indices
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            if (!st.empty()) {
                ans[i].first = arr[st.top()];
                ans[i].second = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<pair<int, int>> prevSmallerEle(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> ans(n, {LLONG_MAX, -1}); // {value, index}
        stack<int> st;                                  // will store indices
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i].first = arr[st.top()];
                ans[i].second = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return false;
        vector<pair<int, int>> last = prevGreaterEle(nums);
        vector<pair<int, int>> prev = prevSmallerEle(nums);

        for (int i = 1; i < n; i++) {
            int k = nums[i];
            int last_greater_el = last[i].first;
            int last_greater_idx = last[i].second;
            if (last_greater_idx == -1)
                continue;
            int prev_smaller_el = prev[last_greater_idx].first;
            int prev_smaller_idx = prev[last_greater_idx].second;
            while (prev_smaller_el >= k && prev_smaller_idx != -1) {
                prev_smaller_el = prev[prev_smaller_idx].first;
                prev_smaller_idx = prev[prev_smaller_idx].second;
                if (prev_smaller_idx == -1) break;
            }
            if (prev_smaller_idx != -1 && prev_smaller_el < k &&
                k < last_greater_el)
                return true;
        }
        return false;
    }
};