class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center,
                          int radius) {
        vector<pair<int, pair<int, int>>> tmp, tmp2;

        int x = center[0], y = center[1];

        int n = towers.size();

        for (int i = 0; i < n; i++) {
            int x1 = towers[i][0], y1 = towers[i][1], q1 = towers[i][2];

            int dist = abs(x - x1) + abs(y - y1);
            if (dist <= radius) {
                tmp.push_back({q1, {x1, y1}});
            }
        }

        if (tmp.empty())
            return {-1, -1};

        sort(tmp.rbegin(), tmp.rend());
        int maxi = tmp[0].first;

        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i].first == maxi)
                tmp2.push_back(tmp[i]);
        }

        sort(tmp2.begin(), tmp2.end());

        return {tmp2[0].second.first, tmp2[0].second.second};
    }
};