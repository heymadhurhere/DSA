class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> del(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = min(nums[i], nums[n - i - 1]);
            int b = max(nums[i], nums[n - i - 1]);

            del[2] += 2;
            del[a + 1] -= 1;
            del[a + b] -= 1;
            del[a + b + 1] += 1;
            del[b + limit + 1] += 1;
        }

        int minMov = n;
        int currMov = 0;

        for (int i = 2; i <= 2 * limit; i++) {
            currMov += del[i];
            minMov = min(minMov, currMov);
        }
        return minMov;
    }
};