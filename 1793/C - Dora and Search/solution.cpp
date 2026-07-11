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
 
bool isMin_Max(ll x, set<ll> &s) {
    return x == *s.begin() || x == *s.rbegin();
}
 
void solve(vi & a) {
    ll n = sz(a);
    ll i = 0, j = n - 1;
    set<ll> s(a.begin(), a.end());
    while (i < j) {
        if (isMin_Max(a[i], s)) {
            s.erase(a[i]);
            i++;
            continue;
        }
        if (isMin_Max(a[j], s)) {
            s.erase(a[j]);
            j--;
            continue;
        }
        break;
    }
    if (i < j) {
        cout << i + 1 << " " << j + 1 << "
";
    } else {
        cout << -1 << "
";
    }
    return;
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
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a);
    }
    
    return 0;
}
 