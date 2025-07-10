class Solution {
public:
    bool solve(vector<int>& arr, int s, vector<bool>& vis) {
        if (arr[s] == 0) {
            return true;
        }
        bool left = false, right = false;
        if (s + arr[s] < arr.size() && !vis[s + arr[s]]) {
            vis[s + arr[s]] = true;
            left = solve(arr, s + arr[s], vis);
        }
        if (s - arr[s] >= 0 && !vis[s - arr[s]]) {
            vis[s - arr[s]] = true;
            right = solve(arr, s - arr[s], vis);
        }
        return left || right;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);
        return solve(arr, start, vis);
    }
};