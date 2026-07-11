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
 
void solve(ll n, ll m) {
    ll c2 = 0, c5 = 0;
 
    ll tmp = n;
    while (tmp > 0 && tmp % 2 == 0) {
        c2++;
        tmp /= 2;
    }
 
    tmp = n;
 
    while (tmp > 0 && tmp % 5 == 0) {
        c5++;
        tmp /= 5;
    }
 
    tmp = n;
 
    ll k = 1;
 
    if (c2 > c5) {
        while (k * 5 <= m && c2 > c5) {
            c5++;
            k *= 5;
        }
    } else if (c2 < c5) {
        while (k * 2 <= m && c2 < c5) {
            c2++;
            k *= 2;
        }
    }
 
    while (k * 10 <= m) {
        k *= 10;
    }
 
    k = k * (m / k);
 
    cout << tmp * k << "
";
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n, m;
        cin >> n >> m;
        solve(n, m);
    }
 
 
    return 0;
}