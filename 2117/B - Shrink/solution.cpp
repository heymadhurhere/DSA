#include <bits/stdc++.h>
using namespace std;
 
vector<int> solve(int n)
{
    int left = 0;
    int right = n - 1;
    vector<int> ans(n);
 
    for (int i = 1; i <= n; ++i)
    {
        if (i % 2 != 0)
        {
            ans[left] = i;
            left++;
        }
        else
        {
            ans[right] = i;
            right--;
        }
    }
 
    return ans;
}
 
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
 
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> res = solve(n);
        for (int x : res)
        {
            cout << x << " ";
        }
        cout << endl;
    }
 
    return 0;
}