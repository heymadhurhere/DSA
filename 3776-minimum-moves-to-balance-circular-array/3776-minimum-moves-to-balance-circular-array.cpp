class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long long neg = 0, pos = 0;
        int n = balance.size();

        for (int i = 0; i < n; i++) {
            if (balance[i] >= 0) {
                pos += balance[i];
            } else {
                neg += balance[i];
            }
        }
        if (abs(neg) > pos)
            return -1;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (balance[i] < 0) {
                idx = i;
                break;
            }
        }
        long long cost = -balance[idx];
        long long ans = 0;

        for (int mov = 1; mov < n && cost > 0; mov++) {
            int left = (idx - mov + n) % n;
            int right = (idx + mov) % n;

            if (balance[left] > 0) {
                long long elm = min((long long)balance[left], cost);
                ans += elm * mov;
                cost -= elm;
            }

            if (cost == 0)
                break;

            if (balance[right] > 0) {
                long long elm = min((long long)balance[right], cost);
                ans += elm * mov;
                cost -= elm;
            }
            if (cost == 0)
                break;
        }
        return ans;
    }
};