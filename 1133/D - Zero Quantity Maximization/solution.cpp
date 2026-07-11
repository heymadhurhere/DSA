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
 
 
void solve(vi& a, vi& b) {
    ll n = sz(a);
    map<pair<ll, ll>, ll> freq;
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (b[i] == 0) cnt++;
        } else {
            ll div = __gcd(abs(a[i]), abs(b[i]));
            ll num = ((-1) * b[i]) / div;
            ll den = a[i] / div;
            if (den < 0) {
                num *= -1;
                den *= -1;
            }
            freq[{num, den}]++;
        }
    }
    ll ans = 0;
    for (auto& it : freq) {
        ans = max(ans, it.S);
    }
    cout << ans + cnt << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;
    cin >> n;
    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi b(n);
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    solve(a, b);
 
    return 0;
}