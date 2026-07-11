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
    bool last, next;
 
    if (s.find("2026") != string::npos) {
        return 0;
    }
 
    if (s.find("2025") == string::npos) {
        return 0;
    }
 
    if (s.find("2025") != string::npos) {
        return 1;
    }
 
    return 0;
 
 
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
}