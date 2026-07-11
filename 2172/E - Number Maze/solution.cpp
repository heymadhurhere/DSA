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
 
void solve(ll n, ll j, ll k) {
    string s = to_string(n);
    string s1 = s, s2 = s;
 
    while (j > 1) {
        next_permutation(s1.begin(), s1.end());
        j--;
    }
 
    while (k > 1) {
        next_permutation(s2.begin(), s2.end());
        k--;
    }
 
    ll len = s.length();
 
    ll cnt = 0;
 
    for (ll i = 0; i < len; i++) {
        if (s1[i] == s2[i]) {
            cnt++;
        }
    }
 
    ll cnt2 = len - cnt;
 
    cout << cnt << "A" << cnt2 << "B
";
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, j, k;
        cin >> n >> j >> k;
        solve(n, j, k);
    }
 
    return 0;
}