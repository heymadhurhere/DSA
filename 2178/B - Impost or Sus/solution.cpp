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
 
    ll cnt = 0;
 
    if (s[0] == 'u') {
        s[0] = 's';
        cnt++;
    }
    if (s[n - 1] == 'u') {
        s[n - 1] = 's';
        cnt++;
    }
 
    for (ll i = 1; i < n - 1; i++) {
        if (s[i] == 'u') {
            if (s[i - 1] != 's') {
                cnt++;
                s[i - 1] = 's';
            }
            if (s[i + 1] != 's') {
                cnt++;
                s[i + 1] = 's';
            }
        }
    }
 
    return cnt;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << "
";
    
    }
}