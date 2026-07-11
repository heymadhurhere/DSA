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
const ll MOD = 1e9 + 7;
 
ll solve(vi& a) {
    ll n = sz(a);
    ll e = a[1], o = a[0], miniO = a[0], miniE = a[1];
    for (ll i = 2; i < n; i++) {
        if ((i + 1) % 2 == 1) {
            o = __gcd(o, a[i]);
            miniO = min(miniO, a[i]);
        } else if ((i + 1) % 2 == 0) {
            e = __gcd(e, a[i]);
            miniE = min(miniE, a[i]);
        }
    }
    bool flag = true;
    for (ll i = 1; i < n; i += 2) {
        if (a[i] % o == 0) {
            flag = false;
            break;
        }
    }
    if (flag) {
        return o;
    }
    flag = true;
    for (ll i = 0; i < n; i += 2) {
        if (a[i] % e == 0) {
            flag = false;
            break;
        }
    }
    if (flag) {
        return e;
    }
    return 0;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(a) << "
";
    }
    return 0;
}