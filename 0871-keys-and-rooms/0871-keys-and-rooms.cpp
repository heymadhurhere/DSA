class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        int n = rooms.size();
        vector<bool> vis(n, false);
        vis[0] = true;
        q.push(0);
        while (!q.empty()) {
            int key = q.front();
            q.pop();
            for (auto& it : rooms[key]) {
                if (!vis[it]) {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        for (bool it : vis) {
            if (!it)
                return false;
        }
        return true;
    }
};