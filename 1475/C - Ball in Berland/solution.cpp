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
 
ll factorial(ll n) {
    ll ans = 1;
    for (ll i = 1; i <= n; i++) {
        ans = (ans * i) % MOD;
    }
    return ans;
}
 
 
void solve(vi& u, vi& b) {
    ll k = sz(u);
    ll ans = (k * (k - 1)) / 2;
 
    unordered_map<ll, ll> u_prev, v_prev;
 
    ll cnt = 0;
    for (ll i = 0; i < k; i++) {
        ll u_i = u[i];
        ll v_i = b[i];
 
        if (u_prev.find(u_i) != u_prev.end()) {
            cnt += u_prev[u_i];
        }
 
        if (v_prev.find(v_i) != v_prev.end()) {
            cnt += v_prev[v_i];
        }
 
        u_prev[u_i]++;
        v_prev[v_i]++;
    }
 
    cout << ans - cnt << endl;
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n1, n2, k;
        cin >> n1 >> n2 >> k;
        vi a(k);
        for (ll i = 0; i < k; i++) {
            cin >> a[i];
        }
        vi b(k);
        for (ll i = 0; i < k; i++) {
            cin >> b[i];
        }
        solve(a, b);
    }
    return 0;
}