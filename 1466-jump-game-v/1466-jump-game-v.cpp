class Solution {
public:
    int solve(vector<int>& arr, int d, int idx, vector<int>& vis) {
        if (idx >= arr.size() || idx < 0)
            return 0;
        if (vis[idx] != -1)
            return vis[idx];
        int left = 1;   // present idx visited h
        //right jao
        for (int i = idx + 1; i < min((int)arr.size(), idx + d + 1); i++) {
            if (arr[idx] > arr[i]) {
                left = max(left, 1 + solve(arr, d, i, vis));
            } else {
                break;
            }
        }
        //left jao
        for (int i = idx - 1; i >= max(0, idx - d); i--) {
            if (arr[i] < arr[idx]) {
                left = max(left, 1 + solve(arr, d, i, vis));
            } else {
                break;
            }
        }
        return vis[idx] = left;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> vis(n, -1);
        int ans = 0;
        // sare index k liye same kaam kro
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(arr, d, i, vis));
        }
        return ans;
    }
};