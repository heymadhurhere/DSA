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
 
 
 
void solve(ll n, ll x, ll y, ll z) {
    ll without = (n + x + y - 1) / (x + y);
    ll with;
    if (x * z >= n) {
        with = (n + x - 1) / x;
    } else {
        ll rem = n - x * z;
        with = z + (rem + x + 10 * y - 1) / (x + 10 * y);
    }
 
    cout << min(without, with) << endl;
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n, x, y, z;
        cin >> n >> x >> y >> z;
        solve(n, x, y, z);
    }
 
 
    return 0;
}