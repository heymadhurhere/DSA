#include <bits/stdc++.h>
using namespace std;
 
void solve(vector<int> &arr)
{
    int n = arr.size();
    unordered_set<int> st;
    for (auto& it : arr) {
        st.insert(it);
    }
    if (st.size() < n) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto& it : arr) {
            cin >> it;
        }
        solve(arr);
    }
    return 0;
}