#include <bits/stdc++.h>
using namespace std;
 
void solve(int r, int b) {
    int R = r / (b + 1);
    int ext = r % (b + 1);
    string s = "";
    for (int i = 0; i <= b; i++) {
        for (int j = 0; j < R; j++) {
            s += 'R';
        }
        if (ext > 0) {
            s += 'R';
            ext--;
        }
        if (i < b) s += 'B';
    }
    cout << s << endl;
    return;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int n, r, b;
        cin >> n >> r >> b;
        solve(r, b);
    }
    return 0;
}