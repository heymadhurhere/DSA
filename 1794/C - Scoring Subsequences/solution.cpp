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
 
    for (ll i = 0; i < n; i++) {
        ll l = 1, r = i + 1;
        while (l <= r) {
            ll m = (l + r) / 2;
            if (a[i - m + 1] >= m) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        ans.pb(r);
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
 
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        
 
        solve(a);
    }
 
    return 0;
}