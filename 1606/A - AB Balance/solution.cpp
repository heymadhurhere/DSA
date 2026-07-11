#include <bits/stdc++.h>
using namespace std;
 
string solve(string s) {
    int n = s.size();
    if (s[0] == s[n - 1]) return s;
    else {
        s[n - 1] = s[0];
    }
    return s;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}