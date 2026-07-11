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
 
ll solve(vi& a) {
    ll n = sz(a);
 
    vi pref(n + 1);
    pref[0] = 0;
 
    for (ll i = 0; i < n; i++) {
        if (i == 0) {
            pref[i + 1] = pref[i] + a[i];
        }
        else {
            pref[i + 1] = pref[i] + abs(a[i]);
        }
    }
 
    vi suf(n + 1);
    suf[n] = 0;
 
    for (ll i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + a[i];
    }
 
    ll ans = -suf[1];
 
    for (ll i = 1; i < n; i++) {
        ans = max(ans, pref[i] - suf[i + 1]);
    }
 
    return ans;
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
        ll res = solve(a);
        cout << res << "
";
    
    }
}