class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<bool> vis(n, false);
        vis[0] = true;
        queue<int> q;
        q.push(0);
        int maxi = 0;
        while (!q.empty()) {
            int idx = q.front();
            if (idx == n - 1)
                return true;
            q.pop();
            for (int i = max(idx + minJump, maxi); i <= min(idx + maxJump, n - 1); i++) {
                if (s[i] == '0' && !vis[i]) {
                    vis[i] = true;
                    q.push(i);
                }
            }
            maxi = min(idx + maxJump + 1, n);
        }
        return false;
    }
};