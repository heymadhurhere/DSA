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
// const ll MOD = 1e9 + 7;
 
ll solve(vi& a) {
    ll n = sz(a);
    vector<pii> v;
    for (ll i = 0; i < n; i++) {
        v.pb({a[i], i + 1});
    }
    sort(all(v));
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            if (v[i].F * v[j].F >= 2 * n) break;
            if (v[i].F * v[j].F == v[i].S + v[j].S) {
                res++;
            }
        }
    }
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(a) << "
";
    }
 
    return 0;
}