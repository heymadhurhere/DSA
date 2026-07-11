#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long, long long>
#define vi vector<long long>
#define vpii vector<pii>
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define F first
#define S second
 
ll solve(ll k, vi& a) {
    ll n =sz(a);
    sort(all(a));
    vi pref(n);
    pref[0] = a[0];
    for (ll i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    ll ans = 0;
    for (ll x = 0; x <= k; x++) {
        ll y = k - x;
        ll l = 2 * x, r = n - y - 1;
        ll sum = pref[r] - (l == 0 ? 0 : pref[l - 1]);
        ans = max(ans, sum);
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vi arr(n);
        for (ll i = 0; i < n; i++) cin >> arr[i];
        cout << solve(k, arr) << "
";
    }
}