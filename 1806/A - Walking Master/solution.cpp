    #include <bits/stdc++.h>
    using namespace std;
 
    int solve(int a, int b, int c, int d) {
        int m = d - b;
        int n = a + m - c;
        return (m < 0 || n < 0) ? -1 : (m + n);
    }
 
 
    int main () {
        int t;
        cin >> t;
        while (t--) {
           int a, b, c, d;
           cin >> a >> b >> c >> d;
           cout << solve(a, b, c, d) << endl;
        }
        return 0;
    }