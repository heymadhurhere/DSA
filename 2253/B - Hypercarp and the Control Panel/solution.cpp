#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<ll, ll>
#define vpii vector<pii>
 
const int MOD = 998244353;
const ll INF = 1e18;
 
 
void solve(vi& a) {
    ll n = sz(a);
    vpii tmp;
    for (ll i = 0; i < n; i++) {
        if (tmp.empty() || tmp.back().F != a[i]) {
            tmp.pb(mp(a[i], 1));
        } else {
            tmp.back().S++;
        }
    }
 
    ll ans = sz(tmp);
 
    for (ll i = 0; i < sz(tmp) - 1; i++) {
        if (tmp[i].S >= 2 && tmp[i + 1].S >= 2) {
            cout << ans + 2 << "
";
            return;
        }
    }
 
    for (ll i = 0; i < sz(tmp); i++) {
        if (tmp[i].S >= 2) {
            bool ok = false;
 
            if (i < sz(tmp) - 1) {
                if (i + 2 >= sz(tmp) || tmp[i + 2].F != tmp[i].F) {
                    ok = true;
                }
            }
 
            bool ok2 = false;
            if (i > 0) {
                if (i - 2 < 0 || tmp[i - 2].F != tmp[i].F) {
                    ok2 = true;
                }
            }
 
            if (ok || ok2) {
                cout << ans + 1 << "
";
                return;
            }
        }
    }
    cout << ans << "
";
    return;
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
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