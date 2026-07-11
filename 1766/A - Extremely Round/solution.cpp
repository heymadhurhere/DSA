    #include <bits/stdc++.h>
    using namespace std;
 
    int solve(int n) {
        int digit = 0;
        int firstdig = 0;
        while (n > 0) {
            firstdig = n % 10;
            n /= 10;
            digit++;
        }
        return (9*(digit - 1) + firstdig);
    }
    int main () {
        int t;
        cin >> t;
        while (t--) {
           int n;
           cin >> n;
           cout << solve(n) << endl;
        }
        return 0;
    }