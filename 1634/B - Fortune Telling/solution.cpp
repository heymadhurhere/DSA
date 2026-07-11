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
 
 
void solve(vi& a, ll x, ll y) {
    ll o = 0;
 
    for (auto it : a) {
        if (it % 2 == 1) {
            o++;
        }
    }
    ll al = x % 2;
    ll bo = 1 - al;
 
    ll aen, ben;
 
    if (o % 2 == 0) {
        aen = al;
        ben = bo;
    } else {
        aen = 1 - al;
        ben = 1 - bo;
    }
 
    if (y % 2 == aen) {
        cout << "Alice
";
        return;
    }
    cout << "Bob
";
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n, x, y;
        cin >> n >> x >> y;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a, x, y);
    }
    return 0;
}