class Solution {
public:
    bool isUpperLeft(int x1, int y1, int x2, int y2) {
        return (x1 <= x2) && (y1 >= y2);
    }

    bool outsideRectangle(int x1, int y1, int x2, int y2, int px, int py) {
        int minX = min(x1, x2);
        int maxX = max(x1, x2);
        int minY = min(y1, y2);
        int maxY = max(y1, y2);

        return (px < minX || px > maxX || py < minY || py > maxY);
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                if (isUpperLeft(x1, y1, x2, y2)) {
                    bool fnd = true;

                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j)
                            continue;

                        int x3 = points[k][0], y3 = points[k][1];
                        if (!outsideRectangle(x1, y1, x2, y2, x3, y3)) {
                            fnd = false;
                            break;
                        }
                    }

                    if (fnd)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};