class Solution {
public:
    int solve(vector<int>& a, int k) {
        int n = a.size();
        int l = 0, r = 0, cnt = 0;
        unordered_map<int, int> mpp;

        while (l <= r and r < n) {
            mpp[a[r]]++;
            while (mpp.size() > k) {
                mpp[a[l]]--;
                if (mpp[a[l]] == 0) {
                    mpp.erase(a[l]);
                }
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};