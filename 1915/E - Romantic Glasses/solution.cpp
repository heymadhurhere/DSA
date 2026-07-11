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
 
 
void solve(vi& a){
    ll sum = 0;
    ll n = sz(a);
 
    vi tmp(n);
    tmp[0] = a[0];
 
    for (ll i = 1; i < n; i++) {
        if (i % 2 == 0) {
            tmp[i] = tmp[i - 1] + a[i];
        } else {
            tmp[i] = tmp[i - 1] - a[i];
        }
 
        if (tmp[i] == 0) {
            cout << "YES
";
            return;
        }
    }
 
    set<ll> s;
 
    for (ll i = 0; i < n; i++) {
        if (s.count(tmp[i])) {
            cout << "YES
";
            return;
        }
        s.insert(tmp[i]);
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
        ll n;
        cin >> n;
 
        vi a(n);
 
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
 
        solve(a);
    }
 
    return 0;
}