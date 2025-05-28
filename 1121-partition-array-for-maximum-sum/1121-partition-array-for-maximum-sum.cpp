class Solution {
public:
    int solve(int idx, int k, int n, vector<int>& arr, vector<int>& dp) {
        if (idx == n)
            return 0;
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int len = 0, ans = INT_MIN, maxi = INT_MIN;
        for (int j = idx; j < min(n, idx + k); j++) {
            len++;
            ans = max(arr[j], ans);
            int sum = len * ans + solve(j + 1, k, n, arr, dp);
            maxi = max(maxi, sum);
        }
        return dp[idx] = maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, k, n, arr, dp);
    }
};