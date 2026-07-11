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
    vi ans(n, 0);
    ans[0] = 1;
 
    for (ll i = 1; i < n; i++) {
        ll e1 = 2 * i + 1;
        ll e2 = 2 * i - 1;
        ans[i] = e1 * e2;
    }
 
    for (ll i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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