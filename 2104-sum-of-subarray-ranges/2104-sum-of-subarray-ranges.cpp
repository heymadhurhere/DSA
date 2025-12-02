class Solution {
public:
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

    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> next = nextSmallerElement(arr);
        vector<int> prev = prevSmallerElement(arr);
        int n = arr.size();

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;

            long long val = ((left) * (right));
            val = (val * (arr[i]));

            total = (total + val);
        }
        return total;
    }

    vector<int> nextGreaterElement(vector<int>& arr) {
        stack<int> st;

        int n = arr.size();
        vector<int> ans(n, n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> prevGreaterElement(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMaxm(vector<int>& arr) {
        vector<int> next = nextGreaterElement(arr);
        vector<int> prev = prevGreaterElement(arr);
        int n = arr.size();

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;

            long long val = ((left) * (right));
            val = (val * (arr[i]));

            total = (total + val);
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxm(nums) - sumSubarrayMins(nums);
    }
};