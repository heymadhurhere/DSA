class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        long long pat1 = 6, pat2 = 6;

        for (int i = 2; i <= n; i++) {
            long long pat1new = (2 * pat1 + 2 * pat2) % MOD;
            long long pat2new = (2 * pat1 + 3 * pat2) % MOD;

            pat1 = pat1new;
            pat2 = pat2new;
        }

        return (pat1 + pat2) % MOD;
    }
};