class Solution {
public:
    int solve(int num, vector<int>& dp) {
        if (num == 1) {
            return 0;
        }

        if (num < 1001 and dp[num] != -1) {
            return dp[num];
        }
        int cnt = 0;
        long long next_num;
        if (num % 2 == 0) {
            next_num = num / 2;
            cnt++;
        }
        if (num % 2 != 0) {
            next_num = num * 3 + 1;
            cnt++;
        }

        cnt += solve(next_num, dp);

        if (num < 1001) {
            dp[num] = cnt;
        }

        return cnt;
    }
    int getKth(int lo, int hi, int k) {
        vector<int> dp(1001, -1);
        dp[1] = 0;

        vector<int> ans(1001, 0);

        for (int i = lo; i <= hi; i++) {
            ans[i] = solve(i, dp);
        }

        vector<pair<int, int>> tmp;

        for (int i = lo; i <= hi; i++) {
            tmp.push_back({ans[i], i});
        }

        sort(tmp.begin(), tmp.end());

        return tmp[k - 1].second;
    }
};