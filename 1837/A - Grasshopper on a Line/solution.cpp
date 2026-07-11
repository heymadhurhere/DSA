#include <bits/stdc++.h>
using namespace std;
 
void solve(int x, int k) {
    bool flag = false;
    if (x % k == 0) flag = true;
    if (!flag) {
        cout << 1 << endl;
        cout << x << endl;
        return;
    }
    else {
        cout << 2 << endl;
        cout << x - 1 << " " << 1 << endl;
        return;
    }
}
 
int main () {
    int t;
    cin >> t;
    while (t--) {
        int x, k;
        cin >> x >> k;
        solve(x, k);
    }
    return 0;
}