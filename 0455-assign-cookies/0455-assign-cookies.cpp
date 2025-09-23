class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int i = 0, j = 0;
        int n = s.size(), m = g.size();
        while (i < n && j < m) {
            if (s[i] >= g[j]) {
                ans++;
                i++;
                j++;
            } else if (s[i] < g[j])
                i++;
        }
        return ans;
    }
};