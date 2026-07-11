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
 
 
ll solve(string& s) {
    ll n = s.length();
    vi pra(n, 0), prb(n, 0), cnt(n, 0);
    cnt[0] = s[0] == 'a';
    for (ll i = 1; i < n; i++) {
        pra[i] = pra[i - 1];
        prb[i] = prb[i - 1];
        cnt[i] = cnt[i - 1];
        if (s[i] == 'a') {
            cnt[i]++;
            prb[i] += i + 1 - cnt[i];
        } else {
            pra[i] += cnt[i];
        }
    }
    vi sufa(n, 0), sufb(n, 0), scnt(n, 0);
    scnt[n - 1] = s[n - 1] == 'a';
    for (ll i = n - 2; i >= 0; i--) {
        sufa[i] = sufa[i + 1];
        sufb[i] = sufb[i + 1];
        scnt[i] = scnt[i + 1];
        if (s[i] == 'a') {
            scnt[i]++;
            sufb[i] += n - i - scnt[i];
        } else {
            sufa[i] += scnt[i];
        }
    }
 
    ll ans = LLONG_MAX;
    for (ll i = 0; i < n; i++) {
        ans = min({ans, pra[i] + sufa[i], prb[i] + sufb[i]});   
    }
    return ans;
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
 