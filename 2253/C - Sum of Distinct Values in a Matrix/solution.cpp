#include <iostream>
#include <vector>
#include <algorithm>
 
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
 
void solve(ll n, ll m, vi&a, vi& b) {
    vpii itm;
    ll i = 0, j = 0;
    ll x = sz(a), y = sz(b);
    
    while (i < x && j < y) {
        if (a[i] == b[j]) {
            itm.pb(mp(a[i], 3));
            i++; 
            j++;
        } else if (a[i] < b[j]) {
            itm.pb(mp(a[i], 1));
            i++;
        } else {
            itm.pb(mp(b[j], 2));
            j++;
        }
    }
    while (i < x) itm.pb(mp(a[i++], 1));
    while (j < y) itm.pb(mp(b[j++], 2));
 
    reverse(all(itm));
 
    ll ans = 0;
    ll cA = 0, cB = 0, tot = 0;
 
    for (auto p : itm) {
        if (tot == n + m - 1) break;
 
        if (p.S == 1) {
            if (cA < n) {
                cA++;
                tot++;
                ans += p.F;
            }
        } else if (p.S == 2) {
            if (cB < m) {
                cB++;
                tot++;
                ans += p.F;
            }
        } else {
            tot++;
            ans += p.F;
        }
    }
 
    cout << ans << "
";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, x, y;
        cin >> n >> m >> x >> y; 
        
        vi a(x), b(y);
        for (ll i = 0; i < x; i++) cin >> a[i];
        for (ll i = 0; i < y; i++) cin >> b[i];
        
        solve(n, m, a, b);
    }
    return 0;
}