#include <bits/stdc++.h>
using namespace std;
 
void solve(long long n)
{
    long long two = 0, three = 0;
    while (n > 0 & n % 3 == 0) {
        n /= 3;
        three++;
    }
    while (n > 0 && n % 2 == 0) {
        n /= 2;
        two++;
    }
    if (n > 1 || two > three) {
        cout << -1 << endl;
    }
    else {
        cout << 2 * three - two << endl;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
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