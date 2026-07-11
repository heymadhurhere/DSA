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
 
 
 
void solve(vi& a, ll k) {
    ll n = sz(a);
    ll i = 0, j = 1;
 
    ll ans = 0;
    while (j < n) {
        if (a[j] * 2 > a[j - 1]) {
            j++;
        } else {
            ll diff = j - i - k;
            if (diff > 0) ans += diff;
            i = j;
            j++;
        }
    }
    ll diff = j - i - k;
    if (diff > 0) ans += diff;
    cout << ans << endl;
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
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a, k);
    }
 
 
    return 0;
}