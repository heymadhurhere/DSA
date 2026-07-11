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
 
void solve(vi& a) {
    ll n = sz(a);
    vi tmp = a;
    sort(all(tmp));
    if (tmp == a) {
        cout << "Bob
";
        return;
    }
 
    vi ans;
    ll l = 0, r = n - 1;
    while (l < r) {
        while (l < r and a[l] == 0) {
            l++;
        }
 
        while (l < r and a[r] == 1) {
            r--;
        }
 
        if (l < r) {
            ans.pb(l + 1);
            ans.pb(r + 1);
            l++;
            r--;
        }
    }
 
    sort(all(ans));
    cout << "Alice
";
    cout << sz(ans) << "
";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "
";
 
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
 
        string s;
        cin >> s;
 
 
        vi a(n);
        for (ll i = 0; i < n; i++) {
            a[i] = s[i] - '0';
        }
        solve(a);
    }
 
    return 0;
}