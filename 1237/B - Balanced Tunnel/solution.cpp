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
 
void solve(vi& a, vi& b) {
    queue<ll> q;
    ll n = sz(a);
 
    for (ll i = 0; i < n; i++) {
        q.push(a[i]);
    }
 
    vector<bool> vis(n + 1, false);
    ll cnt = 0;
 
    for (ll i = 0; i < n; i++) {
        while (!q.empty() && vis[q.front()]) {
            q.pop();
        }
        if (b[i] != q.front()) {
            cnt++;
        } else {
            q.pop();
        }
        vis[b[i]] = true;
    }
    cout << cnt << endl;
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n;
    cin >> n;
 
    vi a(n), b(n);
 
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
 
    solve(a, b);
 
    return 0;
}