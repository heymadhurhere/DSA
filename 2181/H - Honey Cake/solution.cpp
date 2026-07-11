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
 
vi getFactors(ll n) {
    vi ans;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.pb(i);
            if (i != n / i) {
                ans.pb(n / i);
            }
        }
    }
    return ans;
}
 
void solve(ll w, ll h, ll d, ll n) {
    vi factors_w = getFactors(w);
    vi factors_h = getFactors(h);
 
    sort(all(factors_w));
    sort(all(factors_h));
 
 
    for (ll i = 0; i < sz(factors_w); i++) {
        if (n % factors_w[i] != 0) continue;
        for (ll j = 0; j < sz(factors_h); j++) {
            if ((n / factors_w[i]) % factors_h[j] != 0) continue;
            ll r = (n / factors_w[i]) / factors_h[j];
            if (d % r == 0) {
                cout << factors_w[i] - 1 << " " << factors_h[j] - 1 << " " << r - 1 << "
";
                return;
            }
        }
    }
    cout << "-1
";
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
        ll w, h, d;
        cin >> w >> h >> d;
        ll n;
        cin >> n;
        solve(w, h, d, n);
 
    return 0;
}