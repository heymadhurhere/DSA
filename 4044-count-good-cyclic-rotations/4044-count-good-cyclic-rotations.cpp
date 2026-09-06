using ll = long long;
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        ll sum = accumulate(nums.begin(), nums.end(), 0ll);
        ll tmp = 0;
        for (int i = 0; i < n / 2; i++) {
            tmp += nums[i];
        }
        int i = 0, j = (n / 2) - 1;
        int cnt = 0;
        int rot = 0;
        while (rot < n) {
            ll rem = sum - tmp;
            if (tmp > rem)
                cnt++;
            tmp -= nums[i];
            i++;
            j++;
            j %= n;
            tmp += nums[j];
            rot++;
        }
        return cnt;
    }
};