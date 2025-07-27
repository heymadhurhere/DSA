class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(begin(nums), end(nums));
        reverse(begin(nums), end(nums));
        vector<int> ans;
        int tmp = 0;
        for (int i = 0; i < nums.size(); i++) {
            tmp += nums[i];
            sum -= nums[i];
            ans.push_back(nums[i]);
            if (tmp > sum) {
                break;
            }
        }
        return ans;
    }
};