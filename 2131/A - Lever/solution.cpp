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
 
ll solve(vi& a, vi& b) {
    ll n = sz(a);
    ll ans = 0;
    
    for (ll i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            ans += a[i] - b[i];
        }
    }
    return ans + 1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vi a(n), b(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> b[i];
        }
        cout << solve(a, b) << "
";
    }
    return 0;
}