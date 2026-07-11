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
 
ll largestFactor(ll n, ll m) {
    ll ans = -1;
 
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i <= m) {
                ans = max(ans, i);
            }
 
            ll oth = n / i;
 
            if (oth <= m) {
                ans = max(ans, oth);
            }
        }
    }
    return ans;
}
 
 
void solve(ll n, ll k) {
    if (k >= n) {
        cout << 1 <<"
";
        return;
    }
 
    if (k == 1) {
        cout << n << "
";
        return;
    }
    
    ll num = largestFactor(n, k);
    ll ans = n / num;
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
        ll n, k;
        cin >> n >> k;
        solve(n, k);
    }
 
    return 0;
}