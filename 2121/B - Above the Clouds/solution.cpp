#include <bits/stdc++.h>
using namespace std;
 
string solve(string s) {
    int n = s.size();
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    for (int i = 1; i < n - 1; i++) {
        if (freq[s[i] - 'a'] > 1) {
            return "Yes";
        }
    }
    return "No";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s) << '
';
    }
 
    return 0;
}