class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m = score.size();
        int n = score[0].size();
        vector<pair<int, int>> mpp;
        for (int i = 0; i < m; i++) {
            mpp.push_back({score[i][k], i});
        }
        sort(mpp.begin(), mpp.end());
        reverse(mpp.begin(), mpp.end());
        vector<vector<int>> ans(m, vector<int>(n));
        int j = 0;
        for(auto& it : mpp) {
            int row = it.second;
            for (int i = 0; i < n; i++) {
                ans[j][i] = score[row][i];
            }
            j++;
        }
        return ans;
    }
};