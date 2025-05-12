class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0, maxSum = 0;
        while (r < n) {
            sum += nums[r];
            mpp[nums[r]]++;
            while (mpp[nums[r]] > 1) {
                sum -= nums[l];
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(mpp[nums[l]]);
                }
                l++;
            }
            maxSum = max(maxSum, sum);
            r++;
        }
        return maxSum;
    }
};