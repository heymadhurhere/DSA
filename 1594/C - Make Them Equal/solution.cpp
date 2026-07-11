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
 
void solve(string s, char ch) {
    ll n = s.length();
    bool flag = true;
    for (ll i = 0; i < n; i++) {
        if (s[i] != ch) {
            flag = false;
            break;
        } 
    }
    if (flag) {
        cout << 0 << "
";
        return;
    }
 
    ll idx = LLONG_MIN;
 
    if (s[n - 1] == ch) {
        cout << 1 << "
";
        cout << n << "
";
        return;
    }
 
    ll i = n - 2;
    while (i >= 0) {
        if (s[i] == ch) {
            idx = i;
            break;
        }
        i--;
    }
 
    if (idx == LLONG_MIN) {
        cout << 2 << "
";
        cout << n - 1 << " " << n << "
";
        return;
    }
 
    if (idx >= n / 2) {
        cout << 1 << "
";
        cout << idx + 1 << "
";
        return;
    } else {
        cout << 2 << "
";
        cout << n - 1 << " " << n << "
";
        return;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q;
    cin >> q;
    
    while (q--) {
        ll n;
        char ch;
        cin >> n >> ch;
        string s;
        cin >> s;
        solve(s, ch);
    }
 
    return 0;
}