#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<ll, ll>
#define vpii vector<pii>
 
const int MOD = 1e9 + 7;
 
vi tmp;
vvi dp;
 
bool isPalindrome(ll n) {
    string s = to_string(n);
    string t = s;
    reverse(all(t));
    return s == t;
}
 
 
ll count(ll idx, ll tgt) {
    if (tgt == 0) return 1;
    if (tgt < 0 || idx >= sz(tmp)) return 0;
    if (dp[idx][tgt] != -1) return dp[idx][tgt];
    ll take = count(idx, tgt - tmp[idx]);
    ll nottake = count(idx + 1, tgt);
    return dp[idx][tgt] = (take + nottake) % MOD;
}
 
void solve(ll n) {
    ll ans = count(0, n);
    cout << ans << "
";
    return;
}
 
void compute() {
    for (ll i = 1; i < 40005; i++) {
        if (isPalindrome(i)) {
            tmp.pb(i);
        }
    }
    dp.assign(sz(tmp) + 1, vi(40005, -1));
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    compute();
 
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        solve(n);
    }
 
    return 0;
}