#include <bits/stdc++.h>
using namespace std;
 
int solve(long long dx, long long dy, long long xi, long long yi, long long s) {
    if (dx == dy) {
        if ((xi - yi) % s == 0) {
            return 1;
        }
    } else {
        if ((xi + yi) % s == 0) {
            return 1;
        }
    }
    return 0;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long size, side;
        cin >> size >> side;
        int cnt = 0;
        for (long long i = 0; i < size; i++) {
            long long dx, dy, xi, yi;
            cin >> dx >> dy >> xi >> yi;
            cnt = cnt + solve(dx, dy, xi, yi, side);
        }
        cout << cnt << endl;
    }
    return 0;
}