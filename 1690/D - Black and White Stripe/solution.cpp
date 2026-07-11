#include <bits/stdc++.h>
using namespace std;
 
void solve(string& s, int k) {
    int n = s.length();
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == 'W') cnt++;
    }
    int ans = cnt;
    int i = k;
  while (i < n) {
        if (s[i - k] == 'W') cnt--;
        if (s[i] == 'W') cnt++;
        ans = min(ans, cnt);
        i++;
    }
    cout << ans << endl;
    return;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
       string s;
       cin >> s;
        solve(s, k);
    }
    return 0;
}