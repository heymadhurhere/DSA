#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
 
 
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll cntPos = 0, cntNeg = 0;
    for (auto& it : s) {
        if (it == '+') cntPos++;
        else cntNeg++;
    }
    ll q;
    cin >> q;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        ll small = min(a, b);
        ll big = max(a, b);
        if (cntPos == cntNeg) {
            cout << "YES
";
            continue;
        }
        ll chance = abs(cntPos - cntNeg);
        ll diff = big - small;
        if (diff == 0) {
            cout << "NO
";
            continue;
        }
        if (cntPos > cntNeg) {
            
            if ((small * (cntPos - cntNeg)) % diff != 0) {
                cout << "NO
";
                continue;
            }
            ll total = small * (cntPos - cntNeg) / diff;
            if (total <= cntNeg) {
                cout << "YES
";
                continue;
            } else {
                cout << "NO
";
                continue;
            }
        } else if (cntNeg > cntPos) {
            ll diff = big - small;
            if ((small * (cntNeg - cntPos)) % diff != 0) {
                cout << "NO
";
                continue;
            }
            ll total = small * (cntNeg - cntPos) / diff;
            if (total <= cntPos) {
                cout << "YES
";
                continue;
            } else {
                cout << "NO
";
                continue;
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}