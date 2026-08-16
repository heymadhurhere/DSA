using ll = long long;
class Solution {
public:
    ll countInterestingSubarrays(vector<int>& nums, int m, int k) {
        ll ans = 0;
        unordered_map<ll, ll> mpp;
        ll n = nums.size();
        ll cnt = 0;
        vector<int> pref(n, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] % m == k) {
                cnt++;
            }
            pref[i] = (cnt % m);
        }

        ll i = 0;
        while (i < n) {
            if (pref[i] % m == k)
                ans++;
            ll extra = (pref[i] - k + m) % m;

            if (mpp.find(extra) != mpp.end())
                ans += mpp[extra];

            mpp[pref[i] % m]++;
            i++;
        }
        return ans;
    }
};