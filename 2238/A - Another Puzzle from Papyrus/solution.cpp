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
 
void solve(vi a, vi b, ll c) {
    ll n = sz(a);
    ll ans = LLONG_MAX;
    bool ok = true;
    ll cost = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            ok = false;
            break;
        }
        cost += (ll)a[i] - b[i];
    }
    if (ok) ans = min(ans, cost);
    sort(all(a));
    sort(all(b));
    ok = true;
    cost = c;
    for (ll i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            ok = false;
            break;
        }
        cost += (ll)a[i] - b[i];
    }
    if (ok) ans = min(ans, cost);
    cout << (ans == LLONG_MAX ? -1 : ans) << '
';
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    
    ll t;
    cin >> t;
    while (t--) {
        ll n, c;
        cin >> n >> c;
        vi a(n), b(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> b[i];
        }
        solve(a, b, c);
    }
 
    return 0;
}