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
 
string solve(string s, string t) {
    vi freqS(26, 0), freqT(26, 0);
 
    ll n = s.length(), m = t.length();
 
    for (ll i = 0; i < n; i++) {
        freqS[s[i] - 'a']++;
    }
 
    for (ll i = 0; i < m; i++) {
        freqT[t[i] - 'a']++;
    }
 
    for (ll i = 0; i < 26; i++) {
        if (freqT[i] < freqS[i]) {
            return "Impossible";
        }
    }
 
    for (ll i = 0; i < 26; i++) {
        freqT[i] -= freqS[i];
    }
 
    string ans = "";
 
    for (ll i = 0; i < n; i++) {
        char ch = s[i];
        for (ll j = 0; j < ch - 'a'; j++) {
            while (freqT[j] > 0) {
                ans += 'a' + j;
                freqT[j]--;
            }
        }
        ans += ch;
    }
 
    for (ll i = 0; i < 26; i++) {
        while (freqT[i] > 0) {
            ans += i + 'a';
            freqT[i]--;
        }
    }
 
    return ans;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
    ll t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        cout << solve(s, t) << "
";
    }
 
    return 0;
}