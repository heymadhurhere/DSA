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
 
ll solve(vi &a) {
    sort(all(a));
    ll n = sz(a);
    for (ll i = 0; i < n - 1; i++) {
        a[i] = a[i] * (-1);
    }
 
    ll ans = accumulate(all(a), 0LL);
    return ans;
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while (t--) {
        vi a(7);
        for (ll i = 0; i < 7; i++) {
            cin >> a[i];
        }
        cout << solve(a) << "
";
    }
    return 0;
}