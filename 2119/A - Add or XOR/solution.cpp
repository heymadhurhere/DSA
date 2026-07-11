#include <bits/stdc++.h>
using namespace std;
 
int helper(int p, int q, int m, int n) {
    if (p == q) return 0;
 
    int res = 0;
 
    if (p > q) {
        if ((p - q) == 1 && p % 2 == 1) {
            return n;
        } else {
            return -1;
        }
    }
 
    while (p < q) {
        if (p % 2 == 0) {
            if (m <= n) {
                p += 1;
                res += m;
            } else {
                p ^= 1;
                res += n;
            }
        } else {
            p += 1;
            res += m;
        }
    }
 
    return (p == q) ? res : -1;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        cout << helper(u, v, a, b) << endl;
    }
    return 0;
}