class Solution {
public:
    double slope(int x1, int x2, int y1, int y2) {
        double ans = (double)(y2 - y1) / (double)(x2 - x1);
        return ans;
    }
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 1 || points.size() == 2) {
            return points.size();
        }
        int n = points.size();
        int ans = 0;

        // mpp<slope, cnt>
        for (int i = 0; i < n; i++) {
            map<double, int> mpp;
            int infSlope = 0;
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x2 - x1 == 0) {
                    infSlope++;
                } else {
                    double slp = slope(x1, x2, y1, y2);
                    mpp[slp]++;
                }
            }
            int res = infSlope;
            for (auto it : mpp) {
                res = max(res, it.second);
            }
            ans = max(ans, res + 1);
        }
        return ans;
    }
};