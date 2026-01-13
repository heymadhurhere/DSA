class Solution {
public:
    double calcArea(vector<vector<int>>& squares, double mid) {
        double bottom_area = 0;
        for (auto& it : squares) {
            int x = it[0];
            int y = it[1];
            int l = it[2];

            double bottom_y = y * 1.0;
            double top_y = (y + l) * 1.0;
            if (bottom_y <= mid && top_y <= mid) {
                bottom_area += 1LL * l * l * 1.0;
            } else if (bottom_y >= mid)
                continue;
            else {
                bottom_area += (l * (mid - bottom_y)) * 1.0;
            }
        }
        return bottom_area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double yMin = INT_MAX;
        double yMax = INT_MIN;
        long long total_area = 0;

        for (auto it : squares) {
            double x = it[0], y = it[1], l = it[2];
            yMin = min(yMin, y);
            yMax = max(yMax, y + l);
            total_area += l * l;
        }
        double l = yMin, r = yMax;

        while (r - l > 1e-6) { // for precision
            double mid = (l + r) / 2.0;
            if (calcArea(squares, mid) < total_area / 2.0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};