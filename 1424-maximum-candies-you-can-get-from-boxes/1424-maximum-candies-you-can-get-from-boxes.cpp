class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int n = status.size();
        int candy = 0;
        vector<bool> vis(n, false), boxes(n, false);
        queue<int> q;
        for (auto it : initialBoxes) {
            boxes[it] = true;
            if (status[it])
                q.push(it);
        }
        while (!q.empty()) {
            int bx = q.front();
            q.pop();
            if (vis[bx])
                continue;
            vis[bx] = true;
            candy += candies[bx];

            for (auto it : containedBoxes[bx]) {
                boxes[it] = true;
                if (!vis[it] && status[it]) {
                    q.push(it);
                }
            }

            for (auto it : keys[bx]) {
                status[it] = 1;
                if (boxes[it] && !vis[it]) {
                    q.push(it);
                }
            }
        }
        return candy;
    }
};