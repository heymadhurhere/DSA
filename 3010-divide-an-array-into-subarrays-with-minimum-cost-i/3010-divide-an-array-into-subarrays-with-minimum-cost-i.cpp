class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int val1 = nums[0];
        nums.erase(nums.begin(), nums.begin() + 1);
        sort(nums.begin(), nums.end());
        val1 += nums[0] + nums[1];
        return val1;
    }
};