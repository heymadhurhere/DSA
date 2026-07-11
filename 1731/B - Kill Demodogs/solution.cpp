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
 
ll mul_mod(ll a, ll b, ll mod) {
    return (ll)((__int128)a * b % mod);
}
 
ll solve(ll n) {
    ll first = mul_mod(n, n + 1, MOD);
    first = mul_mod(first, 2 * n + 1, MOD);
    ll inv6 = 166666668;
    first = mul_mod(first, inv6, MOD);
 
    ll second = mul_mod(n, n + 1, MOD);
    ll inv2 = (MOD + 1) / 2;
    second = mul_mod(second, inv2, MOD);
 
    ll res = (mul_mod(2, first, MOD) - second + MOD) % MOD;
    res = mul_mod(res, 2022, MOD);
 
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << solve(n) << "
";
    }
    return 0;
}