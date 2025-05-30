class Solution {
public:
    void calculateDis(vector<int>& edges, int dis, int node, vector<int>& ans,
                      vector<bool>& vis) {
        vis[node] = true;
        ans[node] = dis;
        int newNode = edges[node];
        if (newNode != -1 && !vis[newNode]) {
            vis[newNode] = true;
            calculateDis(edges, dis + 1, newNode, ans, vis);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> d1(n, INT_MAX);
        vector<int> d2(n, INT_MAX);
        vector<bool> vis1(n, false);
        calculateDis(edges, 0, node1, d1, vis1);
        vector<bool> vis2(n, false);
        calculateDis(edges, 0, node2, d2, vis2);
        int ans = -1;
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            int maxD = max(d1[i], d2[i]);
            if (maxD < res) {
                res = maxD;
                ans = i;
            }
        }
        return ans;
    }
};