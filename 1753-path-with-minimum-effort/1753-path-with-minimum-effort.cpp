class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        int ans = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int dis = node.first;
            int ux = node.second.first;
            int uy = node.second.second;
            for (int i = 0; i < 4; i++) {
                int vx = ux + dx[i];
                int vy = uy + dy[i];
                if (vx >= 0 && vx < m && vy >= 0 && vy < n) {
                    // naya wala effort purane wale s jyada hai ya nhi check kr
                    // lo. Agr jyada hai to usko consoder kro kyunki maximum
                    // absolute difference lena hai
                    int effort =
                        max(dis, abs(heights[vx][vy] - heights[ux][uy]));
                    if (effort < dist[vx][vy]) {
                        dist[vx][vy] = effort;
                        pq.push({effort, {vx, vy}});
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};