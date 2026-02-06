class Solution {
public:
    int bin(vector<int>& nums, int tmp, int k) {
        int n = nums.size();
        int l = 0, h = n - 1;
        int ans = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] > 1ll * tmp * k) {
                h = mid - 1;
            } else if (nums[mid] <= 1LL * tmp * k) {
                ans = mid;
                l = mid + 1;
            }
            //  else if (nums[mid] == 1LL * tmp * k) {
            //     ans = mid;
            //     break;
            //}
        }
        return ans;
    }
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int idx = bin(nums, nums[i], k);
            int tmp = i + (n - idx - 1);
            ans = min(ans, idx != -1 ? tmp : 1);
        }
        return ans;
    }
};