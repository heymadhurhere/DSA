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
 
void solve(ll a, ll b, ll k) {
    ll steps = max((a + k - 1) / k, (b + k - 1) / k);
    ll x = __gcd(a, b);
    if (x >= steps) {
        cout << 1 << endl;
        return;
    }  
    cout << 2 << endl;
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) {
        ll a, b, k;
        cin >> a >> b >> k;
        solve(a, b, k);
    }
}