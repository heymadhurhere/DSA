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
 
 
void solve(ll a, ll b, ll x) {
    if (a == b) {
        cout << 0 << endl;
        return;
    }
 
    if (x == 1) {
        cout << abs(a - b) << endl;
        return;
    }
 
    ll A = a, B = b;
    vi aa, bb;
 
    while (A > 0) {
        aa.pb(A);
        A /= x;
    }
    aa.pb(0);
 
    while (B > 0) {
        bb.pb(B);
        B /= x;
    }
    bb.pb(0);
 
    ll ans = LLONG_MAX;
    for (ll i = 0; i < sz(aa); i++) {
        for (ll j = 0; j < sz(bb); j++) {
            ll curr = i + j + abs(aa[i] - bb[j]);
            ans = min(ans, curr);
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
        ll a, b, x;
        cin >> a >> b >> x;
        solve(a, b, x);
    }
    return 0;
}