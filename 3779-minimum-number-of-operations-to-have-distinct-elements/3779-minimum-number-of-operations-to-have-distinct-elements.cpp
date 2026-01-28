class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for (auto& it : nums) {
            mpp[it]++;
        }

        int n = nums.size();
        if (mpp.size() == n) return 0;
        if (n < 3) return 1;

        int cnt = 0;

        for (int i = 0; i < n; i += 3) {
            mpp[nums[i]]--;
            if (mpp[nums[i]] == 0) mpp.erase(nums[i]);

            mpp[nums[i + 1]]--;
            if (mpp[nums[i + 1]] == 0) mpp.erase(nums[i + 1]);

            mpp[nums[i + 2]]--;
            if (mpp[nums[i + 2]] == 0) mpp.erase(nums[i + 2]);

            cnt++;
            if (mpp.size() == n - i - 3) return cnt;
        }

        return cnt;
    }
};