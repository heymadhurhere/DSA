#include <bits/stdc++.h>
using namespace std;
 
void solve (vector<int>& arr, int x) {
    int n = arr.size();
    vector<pair<int, int>> range(n);
    for (int i = 0; i < n; i++) {
        range[i] = {arr[i] - x, arr[i] + x};
    }
    int cnt = 0;
    int l = range[0].first;
    int r = range[0].second;
    for (int i = 1; i < n; i++) {
        l = max(l, range[i].first);
        r = min(r, range[i].second);
        if (l > r) {
            cnt++;
            l = range[i].first;
            r = range[i].second;
        }
    }
    cout << cnt << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (auto & it : arr) {
            cin >> it;
        }
        solve(arr, x);
     }
    return 0;
}