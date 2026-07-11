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
 
ll solve(ll n, ll x, ll y) {
    ll lcm = (x * y) / __gcd(x, y);
    ll ul = (n / x) - (n / lcm);
    ll vl = (n / y) - (n / lcm);
    ll f = (n * (n + 1) / 2) - ((n - ul) * (n - ul + 1) / 2);
    ll g = vl * (vl + 1) / 2;
    return f - g;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        cout << solve(n, x, y) << "
";
    }
    
    return 0;
}
 