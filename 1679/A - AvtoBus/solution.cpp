#include <bits/stdc++.h>
using namespace std;
 
void solve(long long n) {
    if (n % 2 == 1 || n < 4) {
        cout << -1 << endl;
        return;
    }
    // minimum buses
    long long min_buses = 0;
    if (n % 6 == 0) {
        min_buses = n / 6;
    }
    else {
        min_buses = n / 6 + 1;
    }
 
    // maximum buses
    long long max_buses = 0;
    if (n % 4 == 0) {
        max_buses = n / 4;
    }
    else {
        long long q = n / 4;
        long long a = q - 1;
        long long b = (n - 4 * a) / 6;
        max_buses = a + b;
    }
 
    cout << min_buses << " " << max_buses << endl;
}
 
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        solve(n);
    }
    return 0;
}