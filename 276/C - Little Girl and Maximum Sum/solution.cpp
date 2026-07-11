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
 
void solve(vi& a, vpii& q) {
    ll n = sz(a);
    vi diff(n + 1, 0);
    for (auto& it : q) {
        ll l = it.F - 1, r = it.S - 1;
        diff[l]++;
        diff[r + 1]--;
    }
 
    vi pref(n + 1);
    pref[0] = diff[0];
    for (ll i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + diff[i];
    }
 
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    sort(pref.rbegin(), pref.rend());
    for (ll i = 0; i < n; i++) {
        if (pref[i] > 0) {
            ans += (a[i] * pref[i]);   
        }
    }
    cout << ans << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n, q;
    cin >> n >> q;
    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vpii qu(q);
    for (ll i = 0; i < q; i++) {
        cin >> qu[i].F >> qu[i].S;
    }
 
    solve(a, qu);
    return 0;
}