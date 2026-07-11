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
 
ll factorial(ll n) {
    ll ans = 1;
    for (ll i = 1; i <= n; i++) {
        ans = (ans * i) % MOD;
    }
    return ans;
}
 
 
void solve(vi& a) {
    ll n = sz(a);
    ll mini = a[0];
 
    for (ll i = 1; i < n; i++) {
        mini = mini & a[i];
    }
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] == mini) cnt++;
    }
 
    if (cnt < 2) {
        cout << 0 << "
";
        return;
    }
 
    ll ans = 1;
    cout << (ans * ((cnt * (cnt - 1)) % MOD) * factorial(n - 2)) % MOD << "
";
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
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a);
    }
    return 0;
}