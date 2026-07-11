#include <bits/stdc++.h>
using namespace std;
 
void solve(string &s, char col)
{
    int n = s.length();
    s += s;
    n *= 2;
 
    int lgi = -1;
    int time = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'g') {
            lgi = i;
        }
        if (s[i] == col) {
            int diff = lgi - i;
            time = max(time, diff);
        }
    }
    cout << time << endl;
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        char ch;
        cin >> n >> ch;
        string s;
        cin >> s;
        solve(s, ch);
    }
    return 0;
}