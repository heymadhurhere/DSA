class Solution {
public:
    bool solve(int mid, string s, vector<int>& order, int k) {
        int n = s.length();
        vector<bool> vis(n, false);
        for (int i = 0; i <= mid; i++) {
            vis[order[i]] = true;
        }

        long long invalid = 0, seg = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                seg++;
            } else {
                invalid += (seg * (seg + 1)) / 2;
                seg = 0;
            }
        }

        // last seg
        if (seg > 0) {
            invalid += (seg * (seg + 1)) / 2;
        }

        long long total = (long long)n * (n + 1) / 2;
        return (total - invalid) >= k;
    }
    int minTime(string s, vector<int>& order, int k) {
        int n = s.length();
        int l = 0, h = n - 1, ans = -1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (solve(mid, s, order, k)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};