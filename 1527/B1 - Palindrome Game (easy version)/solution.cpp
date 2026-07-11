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
// const ll MOD = 1e9 + 7;
 
string solve(string s) {
    ll n = s.length();
    ll zero = 0;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') zero++;
    }
    if (zero == 1) return "BOB";
    if (zero % 2 != 0) return "ALICE";
    else return "BOB";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
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