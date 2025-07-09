class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        vector<int> dur(n);
        for (int i = 0; i < n; i++) {
            dur[i] = endTime[i] - startTime[i];
        }
        vector<int> gap(n + 1);
        gap[0] = startTime[0];
        gap[n] = eventTime - endTime[n - 1];
        for (int i = 1; i < n; i++) {
            gap[i] = startTime[i] - endTime[i - 1];
        }
        vector<int> right(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            right[i] = max(right[i + 1], gap[i + 1]);
        }
        vector<int> left(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            left[i] = max(left[i - 1], gap[i - 1]);
        }
        int ans = 0;
        for (int i = 1; i < n + 1; i++) {
            if (dur[i - 1] <= max(left[i - 1], right[i]))
                ans = max(ans, gap[i - 1] + gap[i] + dur[i - 1]);
            ans = max(ans, gap[i - 1] + gap[i]);
        }
        return ans;
    }
};