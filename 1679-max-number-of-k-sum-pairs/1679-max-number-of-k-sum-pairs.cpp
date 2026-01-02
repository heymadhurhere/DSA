class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0, l = 0, r = n - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == k) {
                cnt++;
                l++;
                r--;
            } else if (sum > k)
                r--;
            else
                l++;
        }
        return cnt;
    }
};