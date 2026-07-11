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
 
 
void solve(vpii& a) {
    ll n = sz(a);
    vpii tmp = a;
    sort(all(a));
    //merge interval
    vvi ans;
    for (ll i = 0; i < n; i++) {
        if (ans.empty() || ans.back()[1] < a[i].F) {
            ans.pb({a[i].F, a[i].S});
        } else {
            ans.back()[1] = max(a[i].S, ans.back()[1]);
        }
    }
 
    if (sz(ans) == 1) {
        cout << -1 << endl;
        return;
    }
 
    ll u = ans.back()[1], l = ans.back()[0];
    for (auto &it : tmp) {
        if (it.F >= l && it.S <= u) {
            cout << 2 << " ";
        } else {
            cout << 1 << " ";
        }
    }
    cout << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vpii a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i].F >> a[i].S;
        }
        solve(a);
    }
 
    return 0;
}