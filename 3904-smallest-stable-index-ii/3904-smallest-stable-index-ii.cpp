class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefMax(n), suffMin(n);

        prefMax[0] = nums[0];
        suffMin[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        int ans = -1;
        for (int i = n - 1; i >= 0; i--) {
            int score = prefMax[i] - suffMin[i];
            if (score <= k) {
                ans = i;
            }
        }
        return ans;
    }
};