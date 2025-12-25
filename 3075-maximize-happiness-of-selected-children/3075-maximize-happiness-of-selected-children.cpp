class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        int n = happiness.size();

        long long ans = 0;
        long long cnt = 0, i = 0;

        while (k > 0) {
            long long to_add = happiness[i] - cnt;
            if (to_add > 0) {
                ans += to_add;
            }
            i++;
            cnt++;
            k--;
        }

        return ans;
    }
};