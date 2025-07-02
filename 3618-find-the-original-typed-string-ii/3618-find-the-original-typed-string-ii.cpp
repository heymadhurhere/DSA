class Solution {
public:
    static const int MOD = 1e9 + 7;
    int countWays(vector<int>& grp, int k, long long total) {
        int n = grp.size();
        vector<int> dp(k, 0);
        dp[0] = 1;

        for (int g : grp) {
            vector<int> new_dp(k, 0);
            long long sum = 0;
            for (int s = 0; s < k; ++s) {
                if (s > 0)
                    sum = (sum + dp[s - 1]) % MOD;
                if (s > g)
                    sum = (sum - dp[s - g - 1] + MOD) % MOD;
                new_dp[s] = sum;
            }
            dp = move(new_dp);
        }

        long long not_req = 0;
        for (int s = n; s < k; ++s)
            not_req = (not_req + dp[s]) % MOD;

        return (total - not_req + MOD) % MOD;
    }

    int possibleStringCount(string word, int k) {
        int n = word.size();
        vector<int> grp;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1])
                cnt++;
            else {
                grp.push_back(cnt);
                cnt = 1;
            }
        }
        grp.push_back(cnt);
        long long total = 1;
        for (auto& it : grp) {
            total = (total * it) % MOD;
        }
        if (k <= (int)grp.size())
            return total;
        return countWays(grp, k, total);
    }
};