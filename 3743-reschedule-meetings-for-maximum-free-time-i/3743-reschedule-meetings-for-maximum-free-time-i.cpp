class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> free(n + 1);
        free[0] = startTime[0];
        free[n] = eventTime - endTime[n - 1];
        for (int i = 0; i < n - 1; i++) {
            free[i + 1] = startTime[i + 1] - endTime[i];
        }
        int maxi = INT_MIN, time = 0;
        int i = 0, j = k;

        for (int p = 0; p <= n && p <= k; p++) {
            time += free[p];
        }
        maxi = max(maxi, time);
        while (j < n) {
            time -= free[i];
            i++;
            j++;
            time += free[j];
            maxi = max(maxi, time);
        }
        return maxi;
    }
};