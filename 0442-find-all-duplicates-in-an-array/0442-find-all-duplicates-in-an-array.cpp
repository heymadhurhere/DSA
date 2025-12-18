class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return {};
        int i = 0;

        while (i < n) {
            int idx = nums[i];
            while (nums[i] != (i + 1)) {
                if (nums[i] == nums[idx - 1])
                    break;
                swap(nums[i], nums[idx - 1]);
                idx = nums[i];
            }
            i++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};