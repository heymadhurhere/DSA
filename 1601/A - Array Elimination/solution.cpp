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
 
 
void solve(vi& a) {
    ll n = sz(a);
 
    vi cnt(30, 0);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < 30; j++) {
            if ((a[i] >> j) & 1) cnt[j]++;
        }
    }
 
    ll gcd = 0;
    for (ll i = 0; i < 30; i++) {
        if (cnt[i] > 0) {
            if (gcd == 0) gcd = cnt[i];
            else gcd = __gcd(gcd, cnt[i]);
        }
    }
 
    if (gcd == 0) {
        for (ll i = 1; i <= n; i++) cout << i << " ";
        cout << "
";
        return;
    }
 
    vi factors;
    for (ll i = 1; i * i <= gcd; i++) {
        if (gcd % i == 0) {
            factors.pb(i);
            if (i * i != gcd) factors.pb(gcd / i);
        }
    }
 
 
    sort(all(factors));
    for (ll f : factors) cout << f << " ";
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
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a);
    }
 
 
    return 0;
}