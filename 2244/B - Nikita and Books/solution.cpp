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
 
 
void solve(vi& a) {
    ll n = sz(a);
    ll ans = 0;
    for (ll i = 0; i < n - 1; i++) {
        if (a[i] < i + 1) {
            cout << "NO
";
            return;
        }
        ll rem = a[i] - (i + 1);
        a[i] = i + 1;
        a[i + 1] += rem;
    }
    if (a[n - 1] < n) {
        cout << "NO
";
        return;
    }
    cout << "YES
";
    return;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) {
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