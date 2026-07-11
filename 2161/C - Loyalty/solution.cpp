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
const ll MOD = 1e9 + 7;
 
 
void solve(ll x, vi& a) {
    ll n = sz(a);
    sort(all(a));
    ll i = 0, j = n - 1;
    ll prev = 0, ans = 0, s = 0;
    vi res;
 
    while (i <= j) {
        if ((s + a[j]) / x > prev) {
            s += a[j];
            ans += a[j];
            prev = s / x;
            res.pb(a[j]);
            j--;
        } else if ((s + a[i]) / x > prev) {
            s += a[i];
            ans += a[i];
            prev = s / x;
            res.pb(a[i]);
            i++;
        } else {
            s += a[i];
            res.pb(a[i]);
            i++;
            prev = s / x;
        }
    }
 
    cout << ans << "
";
    for (ll i = 0; i < sz(res); i++) {
        cout << res[i] << " ";
    }
    cout << "
";
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(x, a);
    }
 
    return 0;
}