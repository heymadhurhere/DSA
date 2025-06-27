class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int, int> mpp;
        int len = INT_MIN;
        while (j < n) {
            mpp[nums[j]]++;
            if (mpp[nums[j]] > k) {
                while (mpp[nums[j]] > k) {
                    mpp[nums[i]]--;
                    i++;
                }
            }
            len = max(len, j - i + 1);
            j++;
        }
        return len;
    }
};