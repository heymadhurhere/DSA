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
 
string solve(ll p, ll q) {
    ll first = (p / 2);
    ll second = (q / 3);
    ll num = min(first, second);
    if (p < q and (p - num * 2) >= (q - num * 3) and -(p - num * 2) + (q - num * 3) <= 1) {
        // cout << (p - num * 2) - (q - num * 3) << endl;
        return "Bob";
    }
    // cout << (p - num * 2) - (q - num * 3) << endl;
    return "Alice";
 
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
    ll t;
    cin >> t;
    while (t--) {
        ll p, q;
        cin >> p >> q;
        cout << solve(p, q) << endl;
    }
 
    return 0;
}