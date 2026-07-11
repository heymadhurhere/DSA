#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve(string s)
{
    int n = s.length();
    ll ans = 0;
    map<char, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[s[i]]++;
        ans += mpp.size();
    }
    cout << ans << endl;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    solve(s);
    }
    return 0;
}