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
 
 
 
void solve(ll x) {
    ll n = 0;
    ll num = x;
    while (num > 0) {
        num /= 10;
        n++;
    }
    ll y = 1;
    while (n--) {
        y *= 10;
    }
    cout << y + 1 << endl;
    return;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll x;
        cin >> x;
        solve(x);
    }
 
    return 0;
}