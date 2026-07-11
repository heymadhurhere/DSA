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
 
ll solve(vi& a) {
    unordered_map<ll, ll> freq;
    ll n = sz(a);
 
    for (ll i = 0; i < n; i++ ) {
        ll diff = a[i] - i;
        freq[diff]++;
    }
 
    ll result = 0;
    for (auto& it : freq) {
        ll cnt = it.S;
        if (cnt > 1) {
            result += cnt * (cnt - 1) / 2;
        }
    }
    return result;
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
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(a) << "
";
    }
 
    return 0;
}