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
 
void dfs(ll v, ll u, vector<vi>& adj, map<pii, ll>& mpp, vi& dp) {
    for (auto it : adj[v]) {
        if (it != u) {
            if (mpp[{v, it}] > mpp[{u, v}]) {
                dp[it] = dp[v];
            } else {
                dp[it] = dp[v] + 1;
            }
            dfs(it, v, adj, mpp, dp);
        }
    }
}
 
void solve(vpii& edges, ll n) {
    vector<vi> adj(n);
    vi dp(n, 0);
 
    map<pii, ll> mpp;
 
    for (ll i = 0; i < sz(edges); i++) {
        adj[edges[i].F - 1].pb(edges[i].S - 1);
        adj[edges[i].S - 1].pb(edges[i].F - 1);
 
        mpp[{edges[i].F - 1, edges[i].S - 1}] = i;
        mpp[{edges[i].S - 1, edges[i].F - 1}] = i;
    }
 
    mpp[{-1, 0}] = -1;
    dp[0] = 1;
 
    dfs(0, -1, adj, mpp, dp);
    cout << *max_element(all(dp)) << endl;
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n;
        cin >> n;
        vpii edges(n - 1);
 
        for (ll i = 0; i < n - 1; i++) {
            cin >> edges[i].F >> edges[i].S;
        }
 
        solve(edges, n);
    }
 
 
    return 0;
}