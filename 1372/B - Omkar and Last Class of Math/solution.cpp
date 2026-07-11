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
 
 
void solve(ll n) {
    ll f = 0;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ll k = n / i;
            cout << k << " " << n - k << "
";
            f = 1;
            break;
            return;
        }
    }
    if (f == 0) {
        cout << 1 << " " << n - 1 << "
";
        return;
    }
}
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n;
        cin >> n;
        solve(n);
    }
 
    return 0;
}