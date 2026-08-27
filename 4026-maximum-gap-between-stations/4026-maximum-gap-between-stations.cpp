class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.length();
        if (n == 1)
            return 0;
        int m = station.length();
        vector<int> fOcc(n, 0);
        vector<int> lOcc(n, 0);
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (skill[i] == station[j]) {
                fOcc[i] = j;
                i++;
                j++;
            } else {
                j++;
            }
        }

        i = n - 1, j = m - 1;
        while (i >= 0 && j >= 0) {
            if (skill[i] == station[j]) {
                lOcc[i] = j;
                i--;
                j--;
            } else {
                j--;
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, lOcc[i] - fOcc[i - 1]);
        }
        return ans;
    }
};