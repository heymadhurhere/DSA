#include <bits/stdc++.h>
using namespace std;
 
void solve(long long a, long long b)
{
    long long num = 0;
    if (b == a) {
        cout << 0 << endl;
        return;
    }
    else if (b > a) {
        if (b % a != 0) {
            cout << -1 << endl;
            return;
        }
        num = b / a;
    }
    else if (b < a) {
        if (a % b != 0) {
            cout << -1 << endl;
            return;
        }
        num = a / b;
    }
 
    bool pow2 = num > 0 && (num & (num - 1)) == 0;
    if (!pow2) {
        cout << -1 << endl;
        return;
    }
    num = log2(num);
    int cnt = 0;
    cnt += num / 3;
    num %= 3;
    cnt += num / 2;
    num %= 2;
    cnt += num;
    cout << cnt << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
    long long a, b;
    cin >> a >> b;
    solve(a, b);
    }
    return 0;
}