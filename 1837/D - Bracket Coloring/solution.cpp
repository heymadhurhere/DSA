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
 
bool isRegular(const string& str) {
    int bal = 0;
    for (char c : str) {
        if (c == '(') bal++;
        else bal--;
        
        if (bal < 0) return false;
    }
    return bal == 0;
}
 
 
void solve(string s) {
    ll n = sz(s);
 
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    
    if (isRegular(s) || isRegular(rev_s)) {
        cout << 1 << "
";
        for (ll i = 0; i < n; i++) {
            cout << 1 << " ";
        }
        cout << "
";
        return;
    }
 
    vi color(n, 0);
    vector<bool> vis(n, false);
 
    ll l = 0, r = n - 1;
    bool u1 = false;
 
    while (l < r) {
        while (l < r && (vis[l] || s[l] != '(')) l++;
        while (l < r && (vis[r] || s[r] != ')')) r--;
        if (l < r) {
            vis[l] = true;
            vis[r] = true;
            color[l] = 1;
            color[r] = 1;
            u1 = true;
            l++;
            r--;
        }
    }
 
    l = 0, r = n - 1;
    bool u2 = false;
 
    while (l < r) {
        while (l < r && (vis[l] || s[l] != ')')) l++;
        while (l < r && (vis[r] || s[r] != '(')) r--;
        if (l < r) {
            vis[l] = true;
            vis[r] = true;
            color[l] = 2; 
            color[r] = 2;
            u2 = true;
            l++;
            r--;
        }
    }
 
    for (ll i = 0; i < n; i++) {
        if (!vis[i]) {
            cout << -1 << "
";
            return;
        }
    }
 
    if (u1 && u2) {
        cout << 2 << "
";
        for (ll i = 0; i < n; i++) {
            cout << color[i] << " ";
        }
        cout << "
";
    } else {
        cout << 1 << "
";
        for (ll i = 0; i < n; i++) {
            cout << 1 << " ";
        }
        cout << "
";
    }
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
        solve(s);
    }
 
 
    return 0;
}