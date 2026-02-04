class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        set<long long> mpp;
        for (int i = 0; i < n; i++) {
            mpp.insert(nums[i]);
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int tmp = nums[i];
            bool fnd = true;
            int cnt = 1;
            while (fnd) {
                long long sq = 1LL * tmp * tmp;
                if (mpp.find(sq) != mpp.end()) {
                    cnt++;
                    tmp = sq;
                } else {
                    fnd = false;
                    ans = max(ans, cnt);
                }
            }
        }
        return ans >= 2 ? ans : -1;
    }
};