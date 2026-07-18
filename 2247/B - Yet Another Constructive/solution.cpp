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
 
 
void solve(ll n, ll k, ll m) {
    if (k > m) {
        cout << "NO
";
        return;
    }
    cout << "YES
";
    vi ans(n);
    for (ll i = 0; i < n; i++) {
        if ((i + 1) % k == 0) {
            ans[i] = m - k + 1;
        } else {
            ans[i] = 1;
        }
    }
    for (ll i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, k, m;
        cin >> n >> k >> m;
        solve(n, k, m);
    }
    return 0;
}