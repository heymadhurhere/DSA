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
 
 
ll solve(vi& a, ll& k) {
    ll n = a.size();
    sort(all(a));
    ll freq = 0, cnt = 0;
    set<ll> s;
    for (ll i = 0; i < n; i++) {
        if (a[i] == k) freq++;
        s.insert(a[i]);
    }
    for (ll i = 0; i < k; i++) {
        if (!s.count(i)) cnt++;
    }
    if (freq >= cnt) return freq;
    return max(cnt, freq);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(a, k) << "
";
    }
    return 0;
}
 