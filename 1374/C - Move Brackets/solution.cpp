#include <bits/stdc++.h>
using namespace std;
 
void solve(string s)
{
    int n = s.length();
    stack<char> st;
    for (int i = 0; i < n; i++) {
        if (!st.empty() && s[i] == ')' && st.top() == '(')
        st.pop();
        else {
            st.push(s[i]);
        }
    }
    cout << st.size() / 2 << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    solve(s);
    }
    return 0;
}