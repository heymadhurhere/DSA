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
 
 
void solve(vi & a) {
    ll n = sz(a);
    sort(all(a));
    map<ll, ll> freq;
    for (ll x : a) {
        freq[x]++;
    }
    
    if (freq.size() == 1) {
        cout << n << endl;
        return;
    }
    vi tmp;
    for (auto& p : freq) {
        tmp.pb(p.F);
    }
 
    ll new_size = sz(tmp);
 
    ll cnt = freq[tmp[0]];
 
    for (ll i = 1; i < new_size; i++) {
        if (tmp[i] == tmp[i - 1] + 1) {
            cnt += max(0LL, freq[tmp[i]] - freq[tmp[i - 1]]);
        }
        else {
            cnt += freq[tmp[i]];
        }
    }
       
    cout << cnt << endl;
    return;
 
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a);
    }
    
    return 0;
}
 