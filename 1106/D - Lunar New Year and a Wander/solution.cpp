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
 
 
void solve(ll m, ll n) {
    vvi adj(n);
    while (m--) {
        ll u, v;
        cin >> u >> v;
        adj[u - 1].pb(v - 1);
        adj[v - 1].pb(u - 1);
    }
    priority_queue<ll, vi, greater<ll>> pq;
    vector<bool> vis(n, false);
    vi ans;
    pq.push(0);
    while (!pq.empty()) {
        ll curr = pq.top();
        pq.pop();
        if (vis[curr]) continue;
        vis[curr] = true;
        ans.pb(curr);
 
        for (auto& it : adj[curr]) {
            if (!vis[it]) {
                pq.push(it);
            }
        }
    }
    for (auto it : ans) {
        cout << it + 1 << " ";
    }
    cout << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n, m;
    cin >> n >> m;
    solve(m, n);
 
    return 0;
}