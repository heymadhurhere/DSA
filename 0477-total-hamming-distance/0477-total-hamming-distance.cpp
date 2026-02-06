class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int tmp = nums[i] ^ nums[j];
                ans += __builtin_popcount(tmp);
            }
        }
        return ans;
    }
};