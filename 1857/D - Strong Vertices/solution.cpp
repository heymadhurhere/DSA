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
 
 
void solve(vi& a, vi& b) {
    ll n = sz(a);
 
    vpii v; // diff and index
    ll maxDiff = LLONG_MIN;
 
    for (ll i = 0; i < n; i++) {
        v.pb(mp(a[i] - b[i], i));
        maxDiff = max(maxDiff, a[i] - b[i]);
    }
 
    ll cnt = 0;
    vi ans;
 
    for (auto it : v) {
        if (it.F == maxDiff) {
            cnt++;
            ans.pb(it.S);
        }
    }
 
    cout << cnt << "
";
 
    for (auto it : ans) {
        cout << it + 1 << " ";
    }
    cout << endl;
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
 
        vi a(n), b(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> b[i];
        }
 
        solve(a, b);
    }
 
    return 0;
}