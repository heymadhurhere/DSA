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
 
 
void solve(string s) {
    ll n = s.length();
    if (n == 1) {
        cout << s << "
";
        return;
    }
 
    if (n == 2 && s[0] == s[1]) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (c != s[0]) {
                string tmp = "";
                tmp += c;
                tmp += s[1];
                cout << tmp << "
";
                return;
            }
        }
    }
    string ans(n, '0');
    ans[0]= s[0];
 
    for (ll i = 1; i < n - 1; i++) {
        if (s[i] == ans[i - 1]) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != ans[i - 1] && c != s[i + 1]) {
                    ans[i] = c;
                    break;
                }
            }
        } else {
            ans[i] = s[i];
        }
    }
    ans[n - 1] = s[n - 1];
    if (ans[n - 2] == ans[n - 1]) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (c != ans[n - 2]) {
                ans[n - 1] = c;
                break;
            }
        }
    }
    cout << ans << "
";
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string s;
    cin >> s;
    solve(s);
 
 
    return 0;
}