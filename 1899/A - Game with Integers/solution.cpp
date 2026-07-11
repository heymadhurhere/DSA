#include <bits/stdc++.h>
using namespace std;
 
string solve(int a) {
    return (a % 3 == 0) ? "Second" : "First";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
}