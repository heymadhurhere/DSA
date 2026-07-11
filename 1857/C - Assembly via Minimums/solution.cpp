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
 
vi solve(vi& a, ll n) {
    sort(all(a));
    vi b;
    ll m = n * (n - 1) / 2;
    ll i = 0, x = n - 1;
    while (x > 0) {
        b.pb(a[i]);
        i += x;
        x--;
    }
    b.pb(1000000000);
    return b;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll m = n * (n - 1) / 2;
        vi a(m);
        for (ll i = 0; i < m; i++) {
            cin >> a[i];
        }
        vi b = solve(a, n);
        for (ll i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << "
";
    }
    
    return 0;
}
 