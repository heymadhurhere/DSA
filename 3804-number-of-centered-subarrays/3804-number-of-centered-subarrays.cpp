class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mpp;
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                mpp[nums[j]]++;
                if (mpp.count(sum)) cnt++;
            }
        }
        return cnt;
    }
};