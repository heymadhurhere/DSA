class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int mini = INT_MAX;
        int ans = arr[0], curr = arr[0], one = INT_MIN;
        for (int i = 1; i < n; i++) {
            if (one != INT_MIN)
                one = max(one + arr[i], ans);
            else
                one = ans;
            ans = max(arr[i], arr[i] + ans);
            curr = max(curr, max(one, ans));
        }
        return curr;
    }
};