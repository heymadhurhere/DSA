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
 
string solve(vi& c) {
    ll n = sz(c);
    sort(all(c));
    if (c[0] != 1) return "NO";
    ll sum = 1;
    for (ll i = 1; i < n; i++) {
        if (c[i] > sum) return "NO";
        sum += c[i];
    }
    return "YES";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vi c(n);
        for (ll i = 0; i < n; i++) {
            cin >> c[i];
        }
        cout << solve(c) << "
";
    }
    return 0;
}