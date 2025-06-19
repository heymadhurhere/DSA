class Solution {
public:
    // int partitionArray(vector<int>& nums, int k) {
    //         int n = nums.size();
    //         int cnt = 0;
    //         vector<bool> vis(n, false);
    //         for (int i = 0; i < n; i++) {
    //             if (!vis[i]) {
    //                 vis[i] = true;
    //                 for (int j = i + 1; j < n && !vis[j]; j++) {
    //                     if (abs(nums[j] - nums[i]) <= k) {
    //                         vis[j] = true;
    //                     }
    //                 }
    //                 cnt++;
    //             }
    //         }
    //         return cnt;
    //     }
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int cnt = 0;
        while (i < n) {
            cnt++;
            int j = i + 1;
            while (j < n && nums[j] - nums[i] <= k) {
                j++;
            }
            i = j;
        }
        return cnt;
    }
};