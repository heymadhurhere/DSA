class Solution {
public:
    bool check(int mid, int maxOpns, vector<int>& nums) {
        int op = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > mid) {
                op += (nums[i] - 1) / mid;
            }
            if (op > maxOpns)
                return false;
        }
        return op <= maxOpns;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int l = 1, h = *max_element(nums.begin(), nums.end());

        int ans = h;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check(mid, maxOperations, nums)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};