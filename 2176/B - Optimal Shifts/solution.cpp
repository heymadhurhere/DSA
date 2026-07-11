#include <bits/stdc++.h>
using namespace std;
 
long long solve(const string &s) {
    long long n = s.size();
    long long mx = 0, cur = 0;
 
    for (long long i = 0; i < n; i++) {
        if (s[i] == '0') cur++, mx = max(mx, cur);
        else cur = 0;
    }
 
    long long l = 0;
    for (long long i = 0; i < n && s[i] == '0'; i++) l++;
 
    long long r = 0;
    for (long long i = n - 1; i >= 0 && s[i] == '0'; i--) r++;
 
    return max(mx, l + r);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s) << "
";
    }
    return 0;
}