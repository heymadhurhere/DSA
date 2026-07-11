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
 
 
void solve(vi& a, ll k) {
    ll n = sz(a);
 
    vector<string> tmp;
 
    for (ll i = 0; i < n; i++) {
        string s = bitset<31>(a[i]).to_string();
        tmp.pb(s);
    }
 
    vi store(31);
 
    for (ll i = 0; i < 31; i++) {
        for (ll j = 0; j < n; j++) {
            if (tmp[j][i] == '0') {
                store[i]++;
            }
        }
    }
 
    vi bits;
 
    for (ll i = 0; i < 31; i++) {
        if (store[i] <= k) {
            bits.pb(i);
            k -= store[i];
        }
    }
 
    ll ans = 0;
    for (ll i = 0; i < bits.size(); i++) {
        ans += (1 << (31 - bits[i] - 1));
    }
    cout << ans << endl;
    return;
}
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n, k;
        cin >> n >> k;
 
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
 
        solve(a, k);
    }
 
    return 0;
}