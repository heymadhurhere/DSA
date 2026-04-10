class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();
        int ans = 0;
        vector<int> vis(n, false);
        int cnt = 0;
        vector<int> minDis(n, INT_MAX);

        minDis[0] = 0;

        while (cnt < n) {
            int currNode = -1;
            int currDis = INT_MAX;

            for (int i = 0; i < n; i++) {
                if (!vis[i] and minDis[i] < currDis) {
                    currNode = i;
                    currDis = minDis[i];
                }
            }

            ans += currDis;
            vis[currNode] = true;
            cnt++;

            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    int wt = abs(points[currNode][0] - points[i][0]) +
                             abs(points[currNode][1] - points[i][1]);
                    if (wt < minDis[i]) {
                        minDis[i] = wt;
                    }
                }
            }
        }
        return ans;
    }
};