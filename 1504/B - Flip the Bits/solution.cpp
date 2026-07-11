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
 
 
void solve(string a, string b) {
    ll cnt0 = 0, cnt1 = 0, flips = 0;
 
    ll n = sz(a);
 
    for (ll i = 0; i < n; i++) {
        if (a[i] == '0') cnt0++;
        else cnt1++;
    }
 
    for (ll i = n - 1; i >= 0; i--) {
        if (flips % 2 == 1) {
            if (a[i] == '0') {
                a[i] = '1';
            } else if (a[i] == '1') {
                a[i] = '0';
            }
        }
 
        if (a[i] != b[i]) {
            if (cnt0 != cnt1) {
                cout << "NO
";
                return;
            }
 
            flips++;
 
            if (a[i] == '1') {
                cnt1--;
                swap(cnt0, cnt1);
            } else if (a[i] == '0') {
                cnt0--;
                swap(cnt0, cnt1);
            }
        } else {
            if (a[i] == '1') {
                cnt1--;
            } else if (a[i] == '0') {
                cnt0--;
            }
        }
    }
    cout << "YES
";
    return;
}
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n;
        cin >> n;
        string a, b;
 
        cin >> a >> b;
 
        solve(a, b);
    }
 
    return 0;
}