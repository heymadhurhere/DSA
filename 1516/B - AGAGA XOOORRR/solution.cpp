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
 
void solve(vi& a)
{
    ll n = sz(a);
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans ^= a[i];
    }
    if (ans == 0) {
        cout << "YES
";
        return;
    }
 
    ll cur = 0, cnt = 0;
    for (ll i = 0; i < n; i++) {
        cur ^= a[i];
        if (cur == ans) {
            cnt++;
            cur = 0;
        }
    }
 
    cout << (cnt > 2 ? "YES
" : "NO
");
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a);
    }
 
    return 0;
}