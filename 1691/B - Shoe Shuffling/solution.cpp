#include <bits/stdc++.h>
using namespace std;
 
void solve(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, pair<int, vector<int>>> mpp;
 
    for (int i = 0; i < n; i++) {
        mpp[arr[i]].first++;
        mpp[arr[i]].second.push_back(i);
    }
    vector<int> ans(n);
    for (auto& it : mpp) {
        if (it.second.first == 1) {
            cout << -1 << endl;
            return;
        }
        vector<int> temp = it.second.second;
        reverse(temp.begin(), temp.end());
        if (temp.size() > 2) {
            swap(temp[temp.size() / 2], temp[temp.size() - 1]);
        }
        for (int i = 0; i < temp.size(); i++) {
            ans[it.second.second[i]] = temp[i];
        }
    }
    for (auto &it : ans) {
        cout << it + 1 << " ";
    }
    cout << endl;
    return;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
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