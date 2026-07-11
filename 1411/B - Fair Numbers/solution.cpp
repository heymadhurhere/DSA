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
 
void solve(long long n)
{
    while (!fair(n)) {
        n += 1;
    }
    cout << n << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        solve(n);
    }
    return 0;
}