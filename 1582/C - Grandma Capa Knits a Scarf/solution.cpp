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
 
ll solve(string s) {
    ll n = s.length();
 
    set<char> st;
    for (ll i = 0; i < n; i++) {
        st.insert(s[i]);
    }
 
    ll ans = LLONG_MAX;
    for (auto ch : st) {
        ll i = 0, j = n - 1;
        ll cnt = 0;
        bool possible = true;
        while (i < j) {
            
            if (s[i] == s[j]) {
                i++;
                j--;
            } else if (s[i] == ch) {
                i++;
                cnt++;
            } else if (s[j] == ch) {
                j--;
                cnt++;
            } else {
                possible = false;
                break;
            }
        }
        if (!possible) {
            cnt = LLONG_MAX;
        }
        ans = min(ans, cnt);
    }
    if (ans == LLONG_MAX) {
        return -1;
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q;
    cin >> q;
    
    while (q--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s) << "
";
    }
 
    return 0;
}