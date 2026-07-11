#include <bits/stdc++.h>
 
using namespace std;
 
string solve(int n, int k) {
    string ans = "";
    for (int i = 0; i < k; ++i) {
        ans += '1';
    }
    for (int i = 0; i < n - k; ++i) {
        ans += '0';
    }
    return ans;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}