#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<ll, ll>
#define vpii vector<pii>
 
const int MOD = 998244353;
const ll INF = 1e18;
 
 
void solve(vi& a, vi& b) {
    ll n = sz(a);
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    
    if ((accumulate(all(a), 0LL) == 0)) {
        cout << -1 << endl;
        return;
    }
 
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] == 1 && b[i] == 0) cnt++;
    }
    if (cnt % 2 != 0) {
        cout << 1 << endl;
        return;
    }
    if (cnt > 0) {
        cout << 2 << endl;
        return;
    }
 
    cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] == 0 && b[i] == 0) cnt++;
    }
    if (cnt > 0){
        cout << 2 << endl;
        return;
    }
    cout << -1 << endl;
    return;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
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