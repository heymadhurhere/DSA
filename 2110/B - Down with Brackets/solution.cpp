#include <bits/stdc++.h>
using namespace std;
string solve(string str) {
    int n = str.length();
    int open = 0, close = 0, entity = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            open++;
        }
        if (str[i] == ')') {
            close++;
        }
        if (open == close) {
            entity++;
        }
    }
    return (entity > 1) ? "YES" : "NO";
}
int main() {
     int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << '
';
    }
    return 0;
}