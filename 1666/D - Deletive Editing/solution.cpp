#include <bits/stdc++.h>
using namespace std;
 
bool solve(string s, string t)
{
    unordered_map<char, vector<int>> mpp;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        mpp[s[i]].push_back(i);
    }
    int k = t.length();
    vector<int> temp(k);
    for (int i = k - 1; i >= 0; i--)
    {
        if (mpp.find(t[i]) != mpp.end())
        {
            temp[i] = mpp[t[i]].back();
            mpp[t[i]].pop_back();
            if (mpp[t[i]].empty())
            {
                mpp.erase(t[i]);
            }
        }
        else
        {
            return false;
        }
    }
    for (int i = 1; i < k; i++)
    {
        if (temp[i] < temp[i - 1])
        {
            return false;
        }
    }
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        cout << (solve(s, t) ? "YES" : "NO") << endl;
    }
    return 0;
}