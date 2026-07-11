#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<ll, ll>
#define vpii vector<pii>
 
const int MOD = 998244353;
 
const ll INF = 1e18;
 
 
void solve(vi& a) {
    ll n = sz(a);
    ll tot = accumulate(all(a), 0LL);
    ll mx = *max_element(all(a));
    if (tot % 2 || mx >  tot - mx) {
        cout << "NO
";
        return;
    }
    cout << "YES
";
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;
    cin >> n;
    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a);
 
    return 0;
}