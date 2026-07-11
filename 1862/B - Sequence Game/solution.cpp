#include <bits/stdc++.h>
using namespace std;
 
vector<int> solve(vector<int> &arr)
{
    vector<int> ans;
    int n = arr.size();
    ans.push_back(arr[0]);
    int i = 1;
    while (i < n) {
        if (arr[i] < arr[i - 1]) {
            ans.push_back(arr[i]);
        }
        ans.push_back(arr[i]);
        i++;
    }
    return ans;
}
 
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<int> temp = solve(arr);
        cout << temp.size() << endl;
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << " ";
        }
        cout << endl;
    }
}