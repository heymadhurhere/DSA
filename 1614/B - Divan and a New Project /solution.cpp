#include <bits/stdc++.h>
using namespace std;
 
void solve(long long n, vector<long long>& arr) {
    vector<pair<long long, long long>> bldng;
    for (long long i = 0; i < n; i++) {
        bldng.push_back({arr[i], i});
    }
    sort(bldng.rbegin(), bldng.rend());
    vector<long long> ans(n + 1);
    ans[0] = 0;
    long long time = 0, cood = 1;
    for (long long i = 0; i < n; i++) {
        ans[bldng[i].second + 1] = cood;
        time += 2 * abs(cood) * bldng[i].first;
        if (cood < 0) {
            cood = abs(cood) + 1;
        } else {
            cood = -cood;
        }
    }
    cout << time << endl;
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << endl;
    return;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> arr(n);
        for (auto& it : arr) {
            cin >> it;
        }
        solve(n, arr);
    }
    return 0;
}