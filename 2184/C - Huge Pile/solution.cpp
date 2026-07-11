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
 
 
ll solve (ll n, ll k) {
    if (k > n) {
        return -1;
    }
 
    for (int i = 0; i <= 32; i++) {
        ll num = 1LL << i;
        ll val = n / num;
        ll rem = n % num;
 
        if (val == k) {
            return i;
        }
 
        if (rem > 0 && val + 1 == k) {
            return i;
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << "
";
    }
    return 0;
}