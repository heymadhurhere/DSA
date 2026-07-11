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
 
void solve(vpii& a)
{
    ll n = sz(a);
    if (n % 2 != 0) {
        cout << 1 << endl;
        return;
    }
    vi x, y;
    for (ll i = 0; i < n; i++) {
        x.pb(a[i].F);
        y.pb(a[i].S);
    }
 
    sort(all(x));
    sort(all(y));
    ll midR = n / 2;
    ll midL = midR - 1;
    ll xWay = x[midR] - x[midL] + 1;
    ll yWay = y[midR] - y[midL] + 1;
    cout << xWay * yWay << endl;
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
        vpii a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i].F >> a[i].S;
        }
        solve(a);
    }
 
    return 0;
}