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
 
void solve(vi& a, ll h) {
    ll n = sz(a);
 
    ll l = 0, r = n - 1;
    ll ans = 0;
 
    while (l <= r) {
        ll mid = l + (r - l)/ 2;
        vi tmp;
        
        for (ll i = 0; i <= mid; i++) {
            tmp.pb(a[i]);
        }
 
        sort(all(tmp));
        
        ll ht = 0, idx = mid;
        while (idx >= 0) {
            ht += tmp[idx];
            idx -= 2;
            
            if (ht > h) { 
                break;
            }
        }
        
        if (ht > h) {
            r = mid - 1;
        } else {
            ans = mid;
            l = mid + 1;
        }
    }
    cout << ans + 1 << "
";
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n, h;
    cin >> n >> h;
    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a, h);
 
    return 0;
}