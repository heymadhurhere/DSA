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
 
void solve(ll n) {
    ll m = 3 * n;
    vi ans(m, 0);
    ll j = 1;
 
    for (ll i = 0; i < m; i += 3) {
        ans[i] = j++;
    }
 
    for (ll i = 1; i < m; i += 3) {
        ans[i] = j++;
        ans[i + 1] = j++;
    }
 
    for (ll i = 0; i < m; i++) {
        cout << ans[i] << " ";
    }
    cout << "
";
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}