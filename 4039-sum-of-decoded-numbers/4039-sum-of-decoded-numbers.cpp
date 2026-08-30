using ll = long long;
const int MOD = 1e9 + 7;
class Solution {
public:
    int dig(ll num) {
        int cnt = 0;
        while (num > 0) {
            num /= 10;
            cnt++;
        }
        return cnt;
    }
    ll pow(ll b, ll e) {
        ll ans = 1;
        b %= MOD;
        while (e > 0) {
            if (e % 2 == 1) {
                ans = (ans * b) % MOD;
            }
            b = (b * b) % MOD;
            e /= 2;
        }
        return ans;
    }
    int sumDecoded(vector<ll>& nums) {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int w = nums[i] % 10;
            ll d = nums[i] / 10;
            ll y = 0;
            int cnt = 0;
            int len = dig(d);
            ll mult = 1;
            while (cnt < len - w) {
                int r = d % 10;
                d /= 10;
                cnt++;
                y = y + r * mult;
                mult *= 10;
            }
            ll x = d;
            ll num = pow(x, y);
            ans = (ans + num) % MOD;
        }
        return ans;
    }
};