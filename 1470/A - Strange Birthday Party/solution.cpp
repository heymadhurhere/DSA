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
 
 
void solve(vi& a, vi& c) {
    ll n = sz(a);
    ll m = sz(c);
 
    sort(all(a));
 
    ll ptr = 0;
 
    ll ans = 0;
 
    for (ll i = n - 1; i >= 0; i--) {
        ll idx = a[i] - 1;
        if (ptr <= idx) {
            ans += c[ptr];
            ptr++;
        } else {
            ans += c[idx];
        }
    }
    cout << ans << endl;
    return;
}
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
 
        vi c(m);
        for (ll i = 0; i < m; i++) {
            cin >> c[i];
        }
 
        solve(a, c);
    }
 
    return 0;
}