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
 
 
 
void solve(vi& a) {
    ll n = sz(a);
 
    vpii p;
 
    for (ll i = 0; i < n; i++) {
        if (a[i] < i + 1) {
            p.pb(mp(a[i], i + 1));
        }
    }
 
    sort(all(p));
 
    ll cnt = 0;
 
    vi elm, idx;
 
    for (auto it : p) {
        elm.pb(it.F);
        idx.pb(it.S);
    }
 
    ll m = sz(elm);
 
    for (ll i = 0; i < m; i++) {
        
        ll ub = upper_bound(all(elm), idx[i]) - elm.begin();
        cnt += m - ub;
        
    }
 
    cout << cnt << endl;
    return;
}
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n;
        cin >> n;
 
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a);
    }
 
    return 0;
}