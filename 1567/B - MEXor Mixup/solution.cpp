#include <bits/stdc++.h>
using namespace std;
 
 
 
void solve(int a, int b) {
    int xori = 0;
    int rem = (a - 1) % 4;
    if (rem == 0) xori = a - 1;
    else if (rem == 1) xori = 1;
    else if (rem == 2) xori = a;
    else xori = 0;
 
    if (xori == b) {
        cout << a << endl;
        return;
    } else if ((xori ^ b) != a) {
        cout << a + 1 << endl;
        return;
    } else {
        cout << a + 2 << endl;
        return;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    long long t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}