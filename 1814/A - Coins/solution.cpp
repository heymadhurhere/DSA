    #include <bits/stdc++.h>
    using namespace std;
 
    string solve(long long n, long long k) {
   if (n % 2 == 0 || (n - k) % 2 == 0) return "YES";
   return "NO";
}
 
 
    int main () {
        int t;
        cin >> t;
        while (t--) {
            long long n, k;
            cin >> n >> k;
            cout << solve(n, k) << endl;
        }
        return 0;
    }