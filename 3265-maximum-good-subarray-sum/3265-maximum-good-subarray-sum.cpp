class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = (long long)nums[i] + pref[i - 1];
        }

        unordered_map<int, int> mpp;

        long long ans = LLONG_MIN;

        mpp[nums[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (mpp.find(nums[i] + k) != mpp.end()) {
                long long curr = pref[i] - pref[mpp[nums[i] + k]] + nums[mpp[nums[i] + k]];
                ans = max(ans, curr);
            }
            if (mpp.find(nums[i] - k) != mpp.end()) {
                long long curr = pref[i] - pref[mpp[nums[i] - k]] + nums[mpp[nums[i] - k]];
                ans = max(ans, curr);
            }
            if (mpp.find(nums[i]) != mpp.end()) {
                if (pref[i] >= pref[mpp[nums[i]]]) continue;
            }
            mpp[nums[i]] = i;
        }
        return (ans == LLONG_MIN ? 0 : ans);
    }
};