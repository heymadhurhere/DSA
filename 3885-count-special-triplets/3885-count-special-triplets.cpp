class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> mppbef, mppaft;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mppaft[nums[i]]++;
        }
        int cnt = 0;
        mppaft[nums[0]]--;
        for (int i = 1; i < n - 1; i++) {
            mppbef[nums[i - 1]]++;
            mppaft[nums[i]]--;
            int temp = 2 * nums[i];
            cnt = (cnt + 1LL * mppbef[temp] * mppaft[temp]) % MOD;
        }
        return cnt;
    }
};