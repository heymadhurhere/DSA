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
 
 
void solve(vector<vi>& a, ll k) {
    ll n = sz(a);
    ll m = sz(a[0]);
 
    map<ll, vi> row, col;
 
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            row[a[i][j]].pb(i);
            col[a[i][j]].pb(j);
        }
    }
 
    ll ans = 0;
    
    for (auto it : row) {
        if (sz(it.S) > 1) {
            sort(it.S.begin(), it.S.end());
            for (ll i = 0; i < sz(it.S); i++) {
                ll left = i * it.S[i];
                ll right = (sz(it.S) - i - 1) * it.S[i];
                ans += left - right;
            }
        }
    }
 
    for (auto it : col) {
        if (sz(it.S) > 1) {
            sort(it.S.begin(), it.S.end());
            for (ll i = 0; i < sz(it.S); i++) {
                ll left = i * it.S[i];
                ll right = (sz(it.S) - i - 1) * it.S[i];
                ans += left - right;
            }
        }
    }
 
    cout << ans << endl;
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n, m;
    cin >> n >> m;
 
    vector<vi> a(n, vi(m));
 
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
 
    solve(a, 1);
    return 0;
}