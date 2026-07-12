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
 
void solve(ll n) {
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
 
    if (n == 2) {
        cout << -1 << endl;
        return;
    }
    vi a(n);
    a[0] = 1;
    a[1] = 2;
    ll sum = 3;
 
    for (ll i = 2; i < n; i++) {
        a[i] = sum;
        sum += a[i];
    }
 
    for (ll i = 0; i < n; i++) {
        cout << a[i] << " ";
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
        solve(n);
    }
    return 0;
}