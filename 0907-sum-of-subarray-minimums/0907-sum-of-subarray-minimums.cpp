class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> nextSmallerElement(vector<int>& arr) {
        stack<int> st;

        int n = arr.size();
        vector<int> ans(n, n);

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
    vector<int> prevSmallerElement(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> next = nextSmallerElement(arr);
        vector<int> prev = prevSmallerElement(arr);
        int n = arr.size();

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;

            long long val = ((left % MOD) * (right % MOD)) % MOD;
            val = (val * (arr[i] % MOD)) % MOD;

            total = (total + val) % MOD;
        }
        return total;
    }
};