#include <bits/stdc++.h>
using namespace std;
 
void solve(long long num) {
    if (num & (num - 1)) {
        cout << "YES
";
    } else {
        cout << "NO
";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long num;
        cin >> num;
        solve(num);
    }
    return 0;
}