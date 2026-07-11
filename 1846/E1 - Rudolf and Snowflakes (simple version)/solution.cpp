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
 
ll calc(ll a, ll b) {
    return log(a) / log(b);
}
 
ll res(ll n, ll k) {
    ll m = calc((n * (k - 1)) + 1, k);
 
    return pow(k, m);
}
 
 
void solve(ll n) {
    for (ll k = 2; k * k < n; k++) {
        ll sum = 1 + k;
        ll curr = k * k;
 
        while (sum + curr <= n) {
            sum += curr;
 
            if (sum == n) {
                cout << "YES
";
                return;
            }
 
            curr *= k;
        }
    }
    cout << "NO" << endl;
    return;
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