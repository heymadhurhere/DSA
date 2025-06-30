class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (auto& it : nums) {
            mpp[it]++;
        }
        if (mpp.size() < 2)
            return 0;
        int maxi = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] == 1) {
                maxi = max(maxi, mpp[nums[i]] + mpp[nums[i + 1]]);
            }
        }
        return maxi;
    }
};