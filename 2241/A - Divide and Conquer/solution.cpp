#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define vi vector<ll>
#define vpii vector<pii>
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define F first
#define S second
 
 
 
void res(ll x, ll y) {
    if (x >= y && x % y == 0) {
        cout << "YES
";
        return;
    }
    cout << "NO
";
    return;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll x, y;
        cin >> x >> y;
        res(x, y);
    }
 
    return 0;
}