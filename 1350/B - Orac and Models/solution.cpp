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
 
 
// done taking help from tutorial
void solve(ll n) {
    vi a(n + 1);
 
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
 
    vi dp(n + 1);
    for (ll i = 0; i <= n; i++) {
        dp[i] = 1;
    }
 
    for (ll i = 2; i <= n; i++) {
        for (ll j = 1; j * j <= i; j++) {
            if (i % j != 0) continue;
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            ll k = i / j;
            if (a[k] < a[i]) dp[i] = max(dp[i], 1 + dp[k]);
        }
    }
 
    cout << *max_element(all(dp)) << endl;
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
        solve(n);
    }
    return 0;
}