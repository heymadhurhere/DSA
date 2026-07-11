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
 
 
void solve(ll n, ll k){
    if (n % 2 == 0) {
        if (k % n == 0) {
            cout << n << endl;
            return;
        } else {
            cout << (k % n) << endl;
            return;
        }
    }
 
    if (n % 2 == 1) {
        if (k < n / 2) {
            cout << k << endl;
            return;
        }
        k = k - 1;
        ll half = n  / 2;
        ll skip = k / half;
        ll pos = (k + skip) % n;
        cout << pos + 1 << endl;
        return;
 
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
        solve(n, k);
    }
 
    return 0;
}