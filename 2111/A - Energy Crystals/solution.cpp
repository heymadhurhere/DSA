#include <bits/stdc++.h>
using namespace std;
 
int solve(int x) {
    int cnt = 0;
    int a = 0, b = 0, c = 0;
    while (a < x || b < x || c < x) {
         if (a < x) {
            a = min(x, 2 * min(b, c) + 1);
            cnt++;
        }
 
        if (b < x) {
            b = min(x, 2 * min(a, c) + 1);
            cnt++;
        }
        
        if (c < x) {
            c = min(x, 2 * min(a, b) + 1);
            cnt++;
        }
    }
    return cnt;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}