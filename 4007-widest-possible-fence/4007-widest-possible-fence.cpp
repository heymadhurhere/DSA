class Solution {
public:
    int maximumWidth(vector<int>& p) {
        unordered_map<int, int> mpp;
        vector<int> unique;
        int n = p.size();

        for (int it : p) {
            if (mpp[it] == 0) {
                unique.push_back(it);
            }
            mpp[it]++;
        }

        unordered_map<int, int> score;
        int ans = 0;

        for (int it : unique) {
            score[it] += mpp[it];
            score[2 * it] += mpp[it] / 2;
        }

        int m = unique.size();

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int x = unique[i];
                int y = unique[j];
                int sum = x + y;

                score[sum] += min(mpp[x], mpp[y]);
            }
        }

        for (auto it : score) {
            ans = max(ans, it.second);
        }
        return ans;
    }
};