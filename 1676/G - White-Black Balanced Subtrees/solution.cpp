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
 
pii dfs(ll node, ll par, vector<vector<ll>>& adj, string& col, ll& cnt) {
    ll b = 0, w = 0;
    if (col[node - 1] == 'B') b++;
    else w++;
 
    for (auto c : adj[node]) {
        if (c == par) continue;
        pii p = dfs(c, node, adj, col, cnt);
        b += p.F;
        w += p.S;
    }
 
    if (b == w) cnt++;
 
    return mp(b, w);
}
 
void solve(vi& a, string col) {
    ll cnt = 0;
 
    ll n = sz(col);
 
    vector<vector<ll>> adj(n + 1);
 
    for (int i = 0; i < n - 1; i++) {
        adj[a[i]].pb(i + 2);
        adj[i + 2].pb(a[i]);
    }
 
    dfs(1, 0, adj, col, cnt);
    cout << cnt << endl;
}
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n;
        cin >> n;
 
        vi a(n - 1);
        for (ll i = 0; i < n - 1; i++) {
            cin >> a[i];
        }
 
        string s;
        cin >> s;
        solve(a, s);
    }
 
    return 0;
}