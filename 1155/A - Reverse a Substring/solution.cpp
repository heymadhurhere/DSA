#include <bits/stdc++.h>
using namespace std;
 
bool fair(long long n) {
    long long num = n;
    while (num > 0) {
        int rem = num % 10;
        if (rem != 0 && n % rem != 0) {
            return false;
        }
        num /= 10;
    }
    return true;
}
 
void solve(string s)
{
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1]) {
            cout << "YES" << endl;
            cout << i + 1 << " " << i + 2 << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    solve(s);
    return 0;
}