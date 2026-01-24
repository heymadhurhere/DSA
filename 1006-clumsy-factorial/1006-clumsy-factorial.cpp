class Solution {
public:
    int clumsy(int n) {
        vector<int> nums;

        for (int i = n; i >= 1; i -= 4) {
            int tmp = i;

            if (i - 1 > 0) {
                tmp *= (i - 1);
            }
            if (i - 2 > 0) {
                tmp /= (i - 2);
            }
            nums.push_back(tmp);
        }
        int ans = nums[0];
        int sum = accumulate(nums.begin() + 1, nums.end(), 0LL);
        ans -= sum;
        int tmp = n - 3;
        for (int i = tmp; i > 0; i -= 4) {
            ans += i;
        }
        return ans;
    }
};