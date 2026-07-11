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
 
 
void solve(vi& a, vpii& queries) {
    ll n = sz(a);
 
    vector<vector<ll>> cntBit(30, vector<ll>(n + 1, 0));
 
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < 30; j++) {
            cntBit[j][i + 1] = cntBit[j][i] + ((a[i] >> j) & 1);
        }
    }
 
    for (auto& q : queries) {
        ll l = q.F, k = q.S;
        
        ll low = l, high = n;
        ll ans = -1;
 
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll curr = 0;
 
            for (ll i = 0; i < 30; i++) {
                if (cntBit[i][mid] - cntBit[i][l - 1] >= mid - l + 1) {
                    curr |= 1 << i;
                }
            }
 
            if (curr >= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << " ";
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
 
        ll m;
        cin >> m;
        vpii queries(m);
        for (ll i = 0; i < m; i++) {
            cin >> queries[i].F >> queries[i].S;
        }
 
        solve(a, queries);
    }
 
 
    return 0;
}