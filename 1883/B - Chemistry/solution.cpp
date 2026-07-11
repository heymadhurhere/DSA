#include <bits/stdc++.h>
using namespace std;
 
string solve(string s, int k) {
    int n = s.length();
    vector<int> hash(26, 0);
    for (int i = 0; i < n; i++) {
        hash[s[i] - 'a']++;
    }
    int cnt = 0;
    for (auto &it : hash) {
        if (it % 2 == 1) cnt++;
    }
    return (cnt > k + 1) ? "NO" : "YES";
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        cout << solve(s, k) << endl;
    }
}