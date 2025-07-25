class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long sum = 0, maxi = 0;
        unordered_map<int, int> mpp;
        while (j < n) {
            sum += nums[j];
            mpp[nums[j]]++;
            while (mpp[nums[j]] > 1) {
                sum -= nums[i];
                mpp[nums[i]]--;
                i++;
            }
            if (j - i + 1 == k) {
                maxi = max(maxi, sum);
                sum -= nums[i];
                mpp[nums[i]]--;
                i++;
            }
            j++;
        }
        return maxi;
    }
};