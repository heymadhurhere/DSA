#include <bits/stdc++.h>
using namespace std;
 
 
 
void solve(string& a, string& b) {
    int m = a.length();
    int n = b.length();
    int cnt = 0;
   vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
   for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        if (a[i - 1] == b[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
            cnt = max(cnt, dp[i][j]);
        }
    }
   }
   cout << m + n - 2 * cnt << endl;
   return;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    long long t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a;
        cin >> b;
        solve(a, b);
    }
    return 0;
}