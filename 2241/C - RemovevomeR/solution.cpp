#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define vi vector<ll>
#define vpii vector<pii>
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define F first
#define S second
 
 
 
void solve(string s) {
    ll n = s.length();
    ll cnt = 0;
    for (ll i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) cnt++;
    }
    if (cnt == 1) {
        cout << 2 << endl;
        return;
    }
    cout << 1 << endl;
    return;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        solve(s);
    }
 
    return 0;
}