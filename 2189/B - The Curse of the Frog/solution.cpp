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
 
ll solve(vi& a, vi& b, vi& c, ll n, ll x) {
    ll m = sz(a);
    ll ma = 0;
 
    for (ll i = 0; i < m; i++) {
        ma = max(ma, a[i] * b[i] - c[i]);
        x -= a[i] * b[i] - a[i];
    }
 
    if (x <= 0) {
        return 0;
    } else {
        if (ma) {
            return (x + ma - 1) / ma;
        } else {
            return -1;
        }
    }
}
 
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;
        vi a(n), b(n), c(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }
        cout << solve(a, b, c, n, x) << "
";
 
    }
 
    return 0;
}