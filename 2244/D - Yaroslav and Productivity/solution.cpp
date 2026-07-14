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
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;
 
 
void solve(vi& a, vi& b) {
    ll n = sz(a);
    ll m = sz(b);
 
    ll ans = 0;
    sort(all(b));
    ll prev = 0;
    for (ll i = 0; i < m; i++) {
        ll curr = b[i];
        ll sum = 0;
        for (ll j = prev; j < curr; j++) {
            sum += a[j];
        }
        ans += abs(sum);
        prev = curr;
    }
 
    for (ll i = prev; i < n; i++) {
        ans += a[i];
    }
    cout << ans << endl;
    return;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vi a(n), b(m);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i < m; i++) {
            cin >> b[i];
        }
        solve(a, b);
    }
    return 0;
}