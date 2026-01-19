class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int l = 1, b = 1;

        int x = hBars.size(), y = vBars.size();
        int tmpL = 1, tmpB = 1;

        for (int i = 0; i < y - 1; i++) {
            if (vBars[i] + 1 == vBars[i + 1])
                tmpL++;
            else
                tmpL = 1;
            l = max(l, tmpL);
        }

        for (int i = 0; i < x - 1; i++) {
            if (hBars[i] + 1 == hBars[i + 1])
                tmpB++;
            else
                tmpB = 1;
            b = max(b, tmpB);
        }

        int size = min(l, b) + 1;
        return size * size;
    }
};