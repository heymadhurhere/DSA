#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long, long long>
#define vi vector<long long>
#define vpii vector<pii>
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define F first
#define S second
 
ll solve(ll n, ll k, ll a, ll b, vector<vector<ll>>& c) {
    ll cost1 = abs(c[a - 1][0] - c[b - 1][0]) + abs(c[a - 1][1] - c[b - 1][1]);
    if (k == 0) return cost1;
    ll ux = c[a - 1][0], uy = c[a - 1][1], vx = c[b - 1][0], vy = c[b - 1][1];
    ll src = LLONG_MAX, dest = LLONG_MAX;
    for (ll i = 0; i < k; i++) {
        ll x = c[i][0], y = c[i][1];
        src = min(src, abs(ux - x) + abs(uy - y));
        dest = min(dest, abs(vx - x) + abs(vy - y));
    }
    return min(cost1, src + dest);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, a, b;
        cin >> n >> k >> a >> b;
        vector<vector<ll>> c(n, vector<ll>(2));
        for (ll i = 0; i < n; i++) cin >> c[i][0] >> c[i][1];
        cout << solve(n, k, a, b, c) << "
";
    }
    return 0;
}