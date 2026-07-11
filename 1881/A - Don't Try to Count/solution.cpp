#include <bits/stdc++.h>
using namespace std;
 
int solve (string x, string s) {
    int n = x.length();
    int m = s.length();
    int cnt = 0;
    for (int i = 0; i <= 5; i++) {
        if (x.find(s) != std::string::npos) {
            return cnt;
        }
        else {
            cnt++;
            x += x;
        }
    }
    return -1;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x;
        cin >> s;
        cout << solve(x, s) << endl;
    }
    return 0;
}