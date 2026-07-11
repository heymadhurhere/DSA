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
    ll n =sz(s);
 
    vi tmp(n, -1);
    stack<ll> st;
 
    for (ll i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            if (!st.empty()) {
                ll u = st.top();
                st.pop();
                tmp[u] = i;
                tmp[i] = u;
            }
        }
    }
 
    ll fuo = n;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '(' && tmp[i] == -1) {
            fuo = i;
            break;
        }
    }
 
    ll luc = -1;
    for (ll i = n - 1; i >= 0; i--) {
        if (s[i] == ')' && tmp[i] == -1) {
            luc = i;
            break;
        }
    }
 
    vi safe;
 
    for (ll i = 0; i < n; i++) {
        if (s[i] == '(' & tmp[i] != -1) {
            ll u = i;
            ll v = tmp[i];
            if (u < fuo) {
                safe.pb(u);
            } else {
                safe.pb(v);
            }
        }
    }
 
    string ans(n, '0');
 
    ll rem = min(k, (ll)sz(safe));
 
    for (ll i = 0; i < rem; i++) {
        ans[safe[i]] = '1';
    }
 
    cout << ans << "
";
    return;
}
 
 
int main() {
 
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