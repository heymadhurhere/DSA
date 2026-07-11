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
// const ll MOD = 1e9 + 7;
 
void solve(vi& a) {
    ll n = sz(a);
    if (a[n - 2] > a[n - 1]) {
        cout << -1 << "
";
        return;
    } else if (a[n - 1] >= 0) {
        cout << n - 2 << "
";
        for (ll i = 0; i < n - 2; i++) {
            cout << i + 1 << " " << n - 1 << " " << n << "
";
        }
    } else  {
        if (is_sorted(all(a))) {
            cout << 0 << "
";
            return;
        } else {
            cout << -1 << "
";
            return;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q;
    cin >> q;
    
    while (q--) {
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