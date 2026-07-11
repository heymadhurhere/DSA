#include <bits/stdc++.h>
using namespace std;
 
int solve(string& s) {
    int n = s.size();
    int contiguousdot = 0;
    int maxcontiguousdot = 0;
    int dotCnt = 0;
    int i = 0;
    while (i < n) {
        if (s[i] == '.') {
            contiguousdot++;
            dotCnt++;
            maxcontiguousdot = max(maxcontiguousdot, contiguousdot);
        }
        else if (s[i] == '#') {
            contiguousdot = 0;
        }
        i++;
    }
    return maxcontiguousdot >= 3 ? 2 : dotCnt;
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
        cout << solve(s) << endl;
    }
}