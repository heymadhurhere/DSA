#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    string s;
    for (int i = 0; i < x; i++)
    {
        cin >> s;
        if (s.length() <= 10)
        {
            cout << s << endl;
        }
        else
        {
            cout << s.front() << s.length() - 2 << s.back() << endl;
        }
    }
    return 0;
}