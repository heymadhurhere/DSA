#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long, long long>
#define vi vector<long long>
#define vpii vector<pii>
#define all(s) s.begin(), s.end()
#define sz(s) (ll)(s).size()
#define F first
#define S second
// const ll MOD = 1e9 + 7;
 
bool canBuy(ll x, ll mid, ll idx, ll val) {
    if (val + (1ll * (idx + 1) * (mid - 1)) <= x) {
        return true;
    }
    return false;
}
 
ll binSrch(ll val, ll idx, ll x) {
    ll low = 1, high = 1e9;
    ll ans = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (canBuy(x, mid, idx, val)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
 
ll solve(vi& a, ll x)
{
    sort(all(a));
    if (a[0] > x) return 0;
    ll n = sz(a);
 
    vi pref(n);
    pref[0] = a[0];
    for (ll i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
 
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += binSrch(pref[i], i, x);
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q;
    cin >> q;
    
    while (q--) {
        ll n, x;
        cin >> n >> x;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
 
        ll ans = solve(a, x);
        cout << ans << "
";
    }
 
    return 0;
}