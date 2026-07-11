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
 
ll solve(ll k, ll x) {
    return k * x + 1;
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    if (cin >> t) {
        while (t--)
        {
            ll k, x;
            cin >> k >> x;
            cout << solve(k, x) << "
";
        }
    }
 
    return 0;
}