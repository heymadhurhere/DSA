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
 
 
void solve(ll x, vpii& m) {
    ll l = x, r = x;
 
    for (auto& it : m) {
        if (it.F <= r and it.S >= l) {
            l = min(l, it.F);
            r = max(r, it.S);
        }
    }
 
    cout << r - l + 1 << '
';
    return;
}
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n, x, m;
        cin >> n >> x >> m;
        vpii a(m);
 
        for (ll i = 0; i < m; i++) {
            cin >> a[i].F >> a[i].S;
        }
 
        solve(x, a);
    }
 
    return 0;
}