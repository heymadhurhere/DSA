class Solution {
public: 
    int f1(vector<int>& nums, int l, int h, int tgt) {
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] < tgt) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return l;
    }
    int f2(vector<int>& nums, int l, int h, int tgt) {
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] <= tgt) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return h;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long cnt = 0;
        // i, j order does not matter
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int lft = f1(nums, i + 1, n, lower - nums[i]);
            int rgt = f2(nums, i + 1, n, upper - nums[i]);
            cnt += rgt - lft;
        }
        return cnt;
    }
};