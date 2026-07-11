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
 
void solve(string s, ll k) {
    ll n = s.length();
    ll cnt1 = 0;
 
    for (ll i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt1++;
        }
    }
 
    if (cnt1 <= k) {
        cout << "Alice" << endl;
        return;
    }
 
    if (cnt1 > k and n >= 2 * k) {
        cout << "Bob" << endl;
        return;
    }
 
    if (cnt1 > k and n < 2 * k) {
        cout << "Alice" << endl;
        return;
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        solve(s, k);
    }
 
    return 0;
}