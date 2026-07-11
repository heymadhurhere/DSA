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
 
void solve(ll n, vpii& p) {
    ll m = sz(p);
    vi arr(n + 1, 1);
 
    for (ll i = 0; i < m; i++) {
        ll L = p[i].F;
        ll R = p[i].S;
 
        if (L > R) {
            swap(L, R);
        }
 
        arr[R] = max(arr[R], L + 1);
    }
 
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        arr[i] = max(arr[i], arr[i - 1]);
        ans += (i - arr[i] + 1);
    }
 
    cout << ans << "
";
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
 
        vpii p(m);
        for (ll i = 0; i < m; i++) {
            cin >> p[i].F >> p[i].S;
        }
        solve(n, p);
    }
 
 
    return 0;
}