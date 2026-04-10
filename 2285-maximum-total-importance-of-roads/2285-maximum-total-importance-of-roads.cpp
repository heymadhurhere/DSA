class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);

        for (auto& it : roads) {
            int u = it[0];
            int v = it[1];

            deg[u]++;
            deg[v]++;
        }

        sort(deg.rbegin(), deg.rend());
        int num = n;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += ((long long)deg[i] * num);
            num--;
        }
        return ans;
    }
};