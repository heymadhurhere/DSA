class Solution {
public:
    int check(int n) {
        int cnt = 0;
        int i = 2;
        int ans = 1 + n;

        while (i <= n / 2) {
            if (n % i == 0) {
                cnt++;
                ans += i;
            }
            if (cnt > 2)
                return 0;
            i++;
        }
        if (cnt == 2)
            return ans;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < 6)
                continue;
            ans += check(nums[i]);
        }
        return ans;
    }
};