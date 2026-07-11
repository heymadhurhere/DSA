#include <bits/stdc++.h>
using namespace std;
 
int solve(vector<int> &arr)
{
    int n = arr.size();
    int pos_min = INT_MAX;
    int neg_max = INT_MIN;
    bool has_pos = false, has_neg = false;
 
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            return 0;
        }
        else if (arr[i] > 0)
        {
            has_pos = true;
            pos_min = min(pos_min, arr[i]);
        }
        else
        {
            has_neg = true;
            neg_max = max(neg_max, arr[i]);
        }
    }
 
    if (!has_pos) return -neg_max;
    if (!has_neg) return pos_min;
 
    return min(pos_min, -neg_max);
}
 
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(arr) << endl;
    return 0;
}