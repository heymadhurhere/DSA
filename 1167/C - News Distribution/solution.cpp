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
 
class DisjointSet {
    
    public:
    vector<ll> rank, parent, size;
    DisjointSet(ll n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (ll i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
 
    // path compression
    ll findUPar(ll node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
 
    }
 
    void unionByRank(ll u, ll v) {
        ll ulp_u = findUPar(u);
        ll ulp_v = findUPar(v);
 
        if (ulp_u == ulp_v) return;
 
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        // both ranks are equal
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
 
    void unionBySize(ll u, ll v) {
        ll ulp_u = findUPar(u);
        ll ulp_v = findUPar(v);
 
        if (ulp_u == ulp_v) return;
 
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
 
 
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vi> adj(n);
    DisjointSet ds(n);
    while (m--) {
        ll k;
        cin >> k;
        if (k == 0) continue;
        vi v;
        while (k--) {
            ll x;
            cin >> x;
            v.pb(x);
        }
 
        for (ll i = 1; i < sz(v); i++) {
            ll u = v[i - 1] - 1, to = v[i] - 1;
            ds.unionBySize(u, to);
        }
    }
 
    for (ll i = 0; i < n; i++) {
        ll ultimate_parent = ds.findUPar(i);
        cout << ds.size[ultimate_parent] << " ";
    }
 
    cout << endl;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}