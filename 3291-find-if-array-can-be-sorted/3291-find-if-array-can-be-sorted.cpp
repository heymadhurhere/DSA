class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<pair<int, int>> tmp;
        if (nums.size() == 1)
            return true;
        int currBit = __builtin_popcount(nums[0]);
        int mini = nums[0], maxi = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int bits = __builtin_popcount(nums[i]);
            if (bits == currBit) {
                mini = min(mini, nums[i]);
                maxi = max(maxi, nums[i]);
            } else {
                tmp.push_back({mini, maxi});
                currBit = bits;
                mini = maxi = nums[i];
            }
        }
        tmp.push_back({mini, maxi});
        if (tmp.size() == 1)
            return true;
        for (int i = 1; i < tmp.size(); i++) {
            if (tmp[i].first < tmp[i - 1].second)
                return false;
        }
        return true;
    }
};