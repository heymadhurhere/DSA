#include <bits/stdc++.h>
using namespace std;
 
void solve(string s)
{
    int n = s.length();
    if (n == 1) {
        cout << 2 << endl;
        return;
    }
    int i = 0, j = 1;
    int maxLen = 1;
    while (j < n) {
        if (s[j] == s[j - 1]) {
            maxLen = max(maxLen, j - i + 1);
        }
        else {
            i = j;
        }
        j++;
    }
    cout << maxLen + 1 << endl;
}
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}