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
 
ll solve(vi& a) {
    ll n = sz(a);
    sort(all(a));
 
    ll num1 = a[0];
    ll num2 = a[1] - a[0];
    if (num1 > num2) return num1;
    return num2;
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    if (cin >> t) {
        while (t--)
        {
            ll n;
            cin >> n;
            vi a(n);
            for (ll i = 0; i < n; i++) {
                cin >> a[i];
            }
            cout << solve(a) << "
";
        }
    }
 
    return 0;
}