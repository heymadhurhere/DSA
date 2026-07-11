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
 
bool solve(string s) {
    ll n = s.length();
    ll k = 0;
    if (n % 2 != 0) {
        if (s[0] == 'b'){
            return false;
        }
        k = 1;
    }
 
    for (; k < n; k += 2) {
        if (s[k] == 'a' and s[k + 1] == 'a') return false;
        if (s[k] == 'b' and s[k + 1] == 'b') return false;
    }
    return true;
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
        string x;
        cin >> x;
        cout << (solve(x) ? "YES" : "NO") << endl;
    }
 
    return 0;
}