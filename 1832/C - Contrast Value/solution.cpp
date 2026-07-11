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
 
bool isInc_dec(ll a, ll b, ll c) {
    if ((a < b && b < c) || (a > b && b > c)) return true;
    return false;
}
ll solve(vi& a) {
    ll n = sz(a);
    ll con_a = 0;
    if (n == 1) return 1;
    if (n == 2) {
        if (a[0] == a[1]) return 1;
        else return 2;
    }
    for (ll i = 0; i < n - 1; i++) {
        con_a += abs(a[i] - a[i + 1]);
    }
    if (con_a == 0) return 1;
    ll i = 0;
    vi tmp;
    while (i < n) {
        if (i + 1 < n & a[i] == a[i + 1]) {
            i++;
        } else {
            tmp.pb(a[i]);
            i++;
        }
    }
    a = tmp;
    tmp.clear();
    n = sz(a);
    ll ans = n;
    i = 0;
    ll j = 1, k = 2;
    while (i < n && j < n && k < n) {
        if (isInc_dec(a[i], a[j], a[k])) {
            ans--;
            j++;
            k++;
        } else {
            i = j;
            j = k;
            k++;
        }
    }
    return ans;
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
        cout << solve(a) << "
";
    }
    
    return 0;
}
 