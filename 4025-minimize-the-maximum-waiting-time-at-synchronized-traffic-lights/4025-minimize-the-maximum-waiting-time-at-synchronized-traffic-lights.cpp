class Solution {
public:
    int minPenalty(int p, vector<int>& l, vector<int>& at) {
        int maxi = *max_element(l.begin(), l.end());
        int ans = 0;

        for (auto it : at) {
            int r = it % p;
            if (r >= maxi) {
                ans = max(ans, p - r);
            }
        }
        return ans;
    }
};