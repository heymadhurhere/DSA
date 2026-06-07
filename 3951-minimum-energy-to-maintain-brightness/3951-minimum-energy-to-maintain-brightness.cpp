class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        long long lights = brightness / 3;
        if (brightness % 3 != 0) {
            lights += 1;
        }

        vector<vector<int>> tmp = merge(intervals);
        long long res = 0;

        for (int i = 0; i < tmp.size(); i++) {
            res += (tmp[i][1] - tmp[i][0] + 1) * lights;
        }
        cout << res;
        return res;
    }
};