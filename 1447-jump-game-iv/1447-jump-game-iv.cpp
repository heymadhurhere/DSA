class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)
            return 0;
        vector<bool> vis(n, 0);
        vis[0] = true;
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) {
            mpp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        int cnt = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                int idx = q.front();
                q.pop();
                if (idx == n - 1)
                    return cnt;
                for (auto& it : mpp[arr[idx]]) {
                    if (!vis[it]) {
                        vis[it] = true;
                        q.push(it);
                    }
                }
                mpp[arr[idx]].clear();
                if (idx + 1 < n && !vis[idx + 1]) {
                    vis[idx + 1] = true;
                    q.push(idx + 1);
                }
                if (idx - 1 >= 0 && !vis[idx - 1]) {
                    vis[idx - 1] = true;
                    q.push(idx - 1);
                }
            }
            cnt++;
        }
        return 23456789;
    }
};