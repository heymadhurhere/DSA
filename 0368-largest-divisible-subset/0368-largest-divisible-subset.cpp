class Solution {
public:
    vector<int> ans;
    int solve(int idx, vector<int>& tmp, int& mini, vector<int>& arr,
              vector<vector<int>>& dp, int prev) {
        if ((int)tmp.size() > mini) {
            ans = tmp;
            mini = (int)tmp.size();
        } else if ((int)tmp.size() == mini) {
            if (tmp > ans) {
                ans = tmp;
            }
        }

        if (idx >= arr.size()) {
            return 0;
        }

        if (dp[idx][prev + 1] != -1 &&
            (int)tmp.size() + dp[idx][prev + 1] < mini) {
            return dp[idx][prev + 1];
        }

        int take = INT_MIN, notTake = INT_MIN;

        if (!tmp.empty()) {
            if (arr[idx] % tmp.back() == 0) {
                // take
                tmp.push_back(arr[idx]);
                take = 1 + solve(idx + 1, tmp, mini, arr, dp, idx);
                // not take
                tmp.pop_back();
                notTake = solve(idx + 1, tmp, mini, arr, dp, prev);
            } else {
                notTake = solve(idx + 1, tmp, mini, arr, dp, prev);
            }
        } else if (tmp.empty()) {
            // take
            tmp.push_back(arr[idx]);
            take = 1 + solve(idx + 1, tmp, mini, arr, dp, idx);
            // not take
            tmp.pop_back();
            notTake = solve(idx + 1, tmp, mini, arr, dp, prev);
        }
        return dp[idx][prev + 1] = max(take, notTake);
    }
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int mini = INT_MIN;
        sort(arr.begin(), arr.end());
        int idx = 0;
        vector<int> tmp;
        int prev = -1;
        solve(idx, tmp, mini, arr, dp, prev);
        return ans;
    }
};