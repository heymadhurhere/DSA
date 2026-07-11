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
 
ll solve(string s) {
    ll n = s.length();
 
    ll ans = n - 1;
 
    for (ll i = 0; i < n - 2; i++) {
        if (s[i] == s[i + 2]) {
            ans--;
        }
    }
    return ans;
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
        cout << solve(s) << "
";
    }
 
    return 0;
}