using ll = long long;
const int MOD = 1e9 + 7;
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < a)
                nums[i] = 0;
            else if (nums[i] >= a & nums[i] <= b)
                nums[i] = 1;
            else
                nums[i] = 2;
        }
        ll ans = 0, cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                ans = (ans + cnt1 + cnt2) % MOD;
            } else if (nums[i] == 1) {
                ans = (ans + cnt2) % MOD;
                cnt1++;
            } else
                cnt2++;
        }
        return (int)ans;
    }
};