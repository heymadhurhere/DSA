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
 
    for (ll i = 0; i < n; i++) {
        ll x = a[i] % (k + 1);
        a[i] += x * k;
    }
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
        for (ll i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "
";
 
    }
 
    return 0;
}