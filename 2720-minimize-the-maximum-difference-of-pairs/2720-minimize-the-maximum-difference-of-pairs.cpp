class Solution {
public:
    bool isValid(vector<int>& nums, int mid, int p) {
        int i = 0;
        int cnt = 0;
        int n = nums.size();
        while (i < n - 1) {
            if (nums[i + 1] - nums[i] <= mid) {
                cnt++;
                i += 2;
            } else {
                i++;
            }
        }
        return cnt >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0)
            return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums[n - 1] - nums[0];
        int ans = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isValid(nums, mid, p)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};