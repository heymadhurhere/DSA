#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long, long long>
#define vi vector<long long>
#define vpii vector<pii>
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define F first
#define S second
 
void solve(string s) {
    int n = s.length();
    bool f = false;
    if (s.find("FFT") != string::npos || s.find("NTT") != string::npos) {
        f = true;
    }
    if (f) {
        sort(all(s));
        reverse(all(s));
    }
    cout << s << endl;
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        solve(s);
    }
}