#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void f(vector<vector<int>>& a, int c);
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<vector<int>> a(n, vector<int>(3));
        for (int i = 0; i < n; ++i) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        f(a, c);
    }
    return 0;
}
 
void f(vector<vector<int>>& a, int c) {
    sort(a.begin(), a.end());
    for (auto& x : a) {
        if (c >= x[0] && c <= x[1] && x[2] >= c) {
            c = x[2];
        }
    }
    cout << c << '
';
}