class Solution {
public:
    struct hashPair {
        size_t operator()(const pair<int, int>& p) const {
            return ((long long)p.first * 31 + p.second);
        }
    };
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
    }

    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int m = buildings.size();
        int cnt = 0;
        vector<pair<int, int>> vec;

        for (int i = 0; i < m; i++) {
            vec.push_back({buildings[i][0], buildings[i][1]});
        }

        vector<pair<int, int>> row_wise = vec, col_wise = vec;
        sort(row_wise.begin(), row_wise.end());
        sort(col_wise.begin(), col_wise.end(), cmp);

        unordered_map<pair<int, int>, pair<bool, bool>, hashPair> mpp;

        for (int i = 1; i < m - 1; i++) {
            int prevRow = row_wise[i - 1].first;
            int nextRow = row_wise[i + 1].first;
            int currRow = row_wise[i].first;

            if (prevRow == currRow && nextRow == currRow) {
                mpp[row_wise[i]].first = true;
            }
            
            int prevCol = col_wise[i - 1].second;
            int nextCol = col_wise[i + 1].second;
            int currCol = col_wise[i].second;

            if (prevCol == currCol && nextCol == currCol) {
                mpp[col_wise[i]].second = true;
            }
        }

        for (auto& it : mpp) {
            if (it.second.first && it.second.second)
                cnt++;
        }

        return cnt;
    }
};