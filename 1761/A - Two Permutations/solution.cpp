    #include <bits/stdc++.h>
    using namespace std;
 
    string solve(int n, int a, int b) {
        return (a + b < n - 1 || (a == b && a == n)) ? "YES" : "NO";
    }
    int main () {
        int t;
        cin >> t;
        while (t--) {
           int n, a, b;
           cin >> n >> a >> b;
           cout << solve(n, a, b) << endl;
        }
        return 0;
    }