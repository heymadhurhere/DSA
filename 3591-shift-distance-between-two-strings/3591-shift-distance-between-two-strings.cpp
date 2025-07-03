class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost,
                            vector<int>& preCost) {
        vector<long long> prefNext(26), prefPrev(26);

        long long ans = 0;
        prefNext[0] = nextCost[25];
        prefPrev[25] = preCost[0];
        for (int i = 1; i < 26; ++i) {
            prefNext[i] = prefNext[i - 1] + nextCost[i - 1];
            prefPrev[25 - i] = prefPrev[25 - i + 1] + preCost[25 - i + 1];
        }
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int st = s[i] - 'a';
            int en = t[i] - 'a';
            if (st < en) {
                ans += min(prefNext[en] - prefNext[st],
                           prefPrev[0] + prefPrev[en] - prefPrev[st]);
            } else {
                ans += min(prefPrev[en] - prefPrev[st],
                           prefNext[25] + prefNext[en] - prefNext[st]);
            }
        }
        return ans;
    }
};