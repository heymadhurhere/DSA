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
 
 
void solve (vi &a, ll h, vector<pii>& b) {
    ll n = sz(a);
    ll m = sz(b);
    
    vi del(n, 0);
 
    vi tmp;
 
    for (auto &it : b) {
        ll idx = it.F - 1;
        ll c = it.S;
 
        if (c == 0) continue;
 
 
        if (a[idx] + del[idx] + c > h) {
            for (auto& i : tmp) {
                del[i] = 0;
            }
            tmp.clear();
        } else {
            if (del[idx] == 0) {
                tmp.pb(idx);
            }
            del[idx] += c;
        }
    }
 
    for (auto &it : tmp) {
        a[it] += del[it];
    }
 
    for (ll i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, h;
        cin >> n >> m >> h;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<pii> b(m);
        for (ll i = 0; i < m; i++) {
            cin >> b[i].F >> b[i].S;
        }
        solve(a, h, b);
        cout << "
";
    }
    return 0;
}