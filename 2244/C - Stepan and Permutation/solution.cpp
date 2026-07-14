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
 
 
void solve(vi& a, ll x, ll y) {
    ll n = sz(a);
    if (is_sorted(all(a))) {
        cout << "YES
";
        return;
    }
    if (x == 1 || y == 1) {
        cout << "YES
";
        return;
    }
 
    // if a*x + b*y = abs(idx - arr[idx]), then only can be sorted
    for (ll i = 0; i < n; i++) {
        if (abs(i + 1 - a[i]) % __gcd(x, y) != 0) {
            cout << "NO
";
            return;
        }
    }
    cout <<"YES
";
    return;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, x, y;
        cin >> n >> x >> y;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a, x, y);
    }
    return 0;
}