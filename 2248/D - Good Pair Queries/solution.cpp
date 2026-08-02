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
 
 
ll solve(string s, string t, ll q) {
    ll n = sz(s);
    vi a(n + 1, 0), b(n + 1, 0);
 
    for (ll i = 1; i <= n; i++) {
        a[i] = a[i - 1];
        b[i] = b[i - 1];
 
        if (s[i - 1] != t[i - 1]) {
            if (s[i - 1] == '0')
                a[i]++;
            else
                b[i]++;
        }
    }
 
    while (q--) {
        ll l, r;
        cin >> l >> r;
 
        ll gap = r - l + 1;
        ll left = a[r] - a[l - 1];
        ll right = b[r] - b[l - 1];
 
        cout << ((left * 2 <= gap && right * 2 <= gap) ? "YES
" : "NO
");
    }
 
    return 0;
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, q;
        cin >> n >> q;
        string s, t;
        cin >> s >> t;
        solve(s, t, q);
    }
    return 0;
}