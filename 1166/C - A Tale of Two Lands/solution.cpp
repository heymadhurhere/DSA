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
 
// 2 4 4
 
void solve(vi& a)
{
    ll n = sz(a);
    for (ll i = 0; i < n; i++) {
        if (a[i] < 0) {
            a[i] = abs(a[i]);
        }
    }
 
    sort(all(a));
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ll idx = upper_bound(all(a), 2 * a[i]) - a.begin();
        ans += (idx - i - 1);
        // if (a[idx] == 2 * a[i]) {
        //     ans++;
        // }
    }
    cout << ans << "
";
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    
        ll n;
        cin >> n;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a);
    
 
    return 0;
}