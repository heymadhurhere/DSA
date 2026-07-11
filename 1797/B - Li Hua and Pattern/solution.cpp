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
 
string solve(vector<vi>& c, ll k) {
    ll cnt = 0;
    ll n = c.size();
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (c[i][j] != c[n - i - 1][n - j - 1]) {
                cnt++;
            }
        }
    }
    cnt /= 2;
    if (cnt > k) return "NO";
    ll diff = k - cnt;
    if (diff % 2 == 0) return "YES";
    else {
        if (n % 2 == 1) return "YES";
    }
    return "NO";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<vi> c(n, vi(n));
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                cin >> c[i][j];
            }
        }
        cout << solve(c, k) << "
";
    }
    return 0;
}