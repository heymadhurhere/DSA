class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = 0;
        int idx = 0;
        bool fnd = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                idx = i;
                ans = nums[idx];
                fnd = true;
                break;
            }
        }
        if (fnd) {
            for (int i = idx + 1; i < nums.size(); i++) {
                if (nums[i] != i) {
                    ans &= nums[i];
                }
            }
        }
        return ans;
    }
};