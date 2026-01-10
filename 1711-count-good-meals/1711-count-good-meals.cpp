class Solution {
public:
    const int MOD = 1e9 + 7;
    long long nc2(long long num) { return (num * (num - 1)) / 2; }
    int countPairs(vector<int>& deliciousness) {
        int n = deliciousness.size();
        if (n == 1)
            return 0;
        int max_sum =
            *max_element(deliciousness.begin(), deliciousness.end()) * 2;
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[deliciousness[i]]++;
        }
        int cnt = 0;
        int to_sub = 0;
        int idx = log2(max_sum) + 1;
        for (auto& it : mpp) {
            int num = it.first;
            for (int sum = 1; sum <= (1 << idx); sum <<= 1) {
                int rem = sum - num;
                if (mpp.count(rem)) {
                    if (rem == num) {
                        cnt = (cnt + nc2(mpp[rem])) % MOD;

                    } else if (rem > num) {
                        cnt = (cnt + (long long)mpp[num] * mpp[rem]) % MOD;
                    }
                }
            }
        }
        return cnt % MOD;
    }
};