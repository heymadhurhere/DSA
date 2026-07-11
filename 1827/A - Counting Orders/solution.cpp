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
const ll MOD = 1e9 + 7;
 
ll solve(vi& a, vi& b) {
    sort(all(a));
    sort(all(b), greater<ll>());
    ll n = sz(a);
    ll ans = 1;
    for (ll i = 0; i < n; i++) {
        ll tmp = (upper_bound(all(a), b[i]) - a.begin());
        ll cnt = (n - tmp);
        ans = ans * max(cnt - i, 0ll) % MOD;
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vi a(n), b(n);
        for (ll i = 0; i < n; i++) cin >> a[i];
        for (ll i = 0; i < n; i++) cin >> b[i];
        cout << solve(a, b) << "
";
    }
}