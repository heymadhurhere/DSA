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
 
    vi ans;
 
    ll l = 0;
    ans.pb(a[0]);
 
    while (l < n - 1) {
 
        ll r = l;
 
        while (r + 1 < n && (a[r] < a[r + 1]) == (a[l] < a[l + 1])) {
            r++;
        }
 
        ans.pb(a[r]);
 
        l = r;
    }
 
    cout << sz(ans) << "
";
 
    for (ll i = 0; i < sz(ans); i++) {
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
        vi a(n);
 
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a);
    }
 
    return 0;
}