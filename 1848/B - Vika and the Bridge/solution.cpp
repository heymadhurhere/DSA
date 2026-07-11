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
 
ll solve(vi& a, ll k) {
    ll n = sz(a);
    vector<vi> clr(k + 1);
    for (ll i = 1; i <= k; i++) {
        clr[i].pb(0);
    }
    for (ll i = 0; i < n; i++) {
        clr[a[i]].pb(i + 1);
    }
    for (ll i = 1; i <= k; i++) {
        clr[i].pb(n + 1);
    }
    ll ans = LLONG_MAX;
    vector<priority_queue<ll>> pq(k + 1);
    for (ll i = 1; i <= k; i++) {
        for (ll j = 1; j < sz(clr[i]); j++) {
            ll gap = clr[i][j] - clr[i][j - 1] - 1;
            pq[i].push(gap);
        }
        ll maxi = pq[i].top();
        pq[i].pop();
        if (maxi % 2 == 0) {
            pq[i].push(maxi / 2);
            pq[i].push((maxi / 2) - 1);
        } else {
            pq[i].push(maxi / 2);
            pq[i].push(maxi / 2);
        }
        ans = min(ans, pq[i].top());
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll res = solve(a, k);
        cout << res << "
";
    }
    
    return 0;
}
 