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
 
void solve(vi& a, vi& b, ll k1, ll k2) {
    ll n = sz(a);
    ll tot_op = k1 + k2;
    priority_queue<ll> pq;
    for (ll i = 0; i < n; i++) {
        pq.push(abs(a[i] - b[i]));
    }
 
    while (tot_op > 0) {
        ll top = pq.top();
        pq.pop();
        pq.push(abs(top - 1));
        tot_op--;
    }
 
    ll ans = 0;
    while (!pq.empty()) {
        ll top = pq.top();
        pq.pop();
        ans += top * top;
    }
    cout << ans << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n, k1, k2;
    cin >> n >> k1 >> k2;
    vi a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    solve(a, b, k1, k2);
 
    return 0;
}