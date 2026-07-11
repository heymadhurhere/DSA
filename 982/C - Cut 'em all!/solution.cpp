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
 
const int MOD = 1e9 + 7;
 
const ll INF = 1e18;
 
void dfs(ll node, ll par, vvi& adj, vi& ans) {
    ans[node] = 1;
    for (auto& it : adj[node]) {
        if (it != par) {
            dfs(it, node, adj, ans);
            ans[node] += ans[it];
        }
    }
}
 
void solve(ll n) {
    vvi adj(n);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    if (n % 2 != 0) {
        cout << -1 << endl;
        return;
    }
 
    vi ans(n, 0);
    dfs(0, -1, adj, ans);
    ll total = ans[0];
    ll cnt = 0;
 
    for (ll i = 0; i < n; i++) {
        if (ans[i] % 2 == 0) cnt++;
    }
    cout << cnt - 1 << endl;
    return;
    
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;
    cin >> n;
    solve(n);
 
    return 0;
}