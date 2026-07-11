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
 
void solve(vpii& a, ll total_nodes) {
    ll n = sz(a);
 
    vector<vector<ll>> adj(n + 2);
    for (ll i = 0; i < n; i++) {
        ll u = a[i].F;
        ll v = a[i].S;
 
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    // bfs and level order traversal to store number of nodes at each level
    queue<pair<ll, ll>> q;
    q.push({1, 0});
    map<ll, ll> mpp; // node->level
    vector<bool> vis(total_nodes + 1, false);
 
    while (!q.empty()) {
        ll u = q.front().F;
        ll level = q.front().S;
        q.pop();
 
        mpp[u] = level;
        vis[u] = true;
 
        for (ll v : adj[u]) {
            if (!vis[v]) {
                q.push({v, level + 1});
            }
        }
    }
 
    map<ll, ll> mpp2; // level->number of nodes
    for (auto it : mpp) {
        mpp2[it.S]++;
    }
 
    ll ans = 0;
 
    ll cnt_even = 0;
    ll cnt_odd = 0;
 
    for (auto it : mpp2) {
        ll level = it.first;
        ll num_nodes = it.second;
 
        if (level % 2 == 0) {
            cnt_even += num_nodes;
        } else {
            cnt_odd += num_nodes;
        }
    }
 
    ans = (cnt_even * cnt_odd) - n;
 
    cout << ans << "
";
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n;
    cin >> n;
    vpii a(n - 1);
    for (ll i = 0; i < n - 1; i++) {
        cin >> a[i].F >> a[i].S;
    }
    solve(a, n);
 
    return 0;
}