#include <bits/stdc++.h>
using namespace std;
 
static bool customSort(pair<long long, long long>& a, pair<long long, long long>& b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}
 
void solve(vector<long long>& arr, long long k) {
    long long n = arr.size();
    for (long long i = 0; i < n; i++) {
        arr[i] = arr[i] % k;
        if (arr[i] == 0) {
            arr[i] = k;
        }
    }
    vector<pair<long long, long long>> mpp;
    for (long long i = 0; i < n; i++) {
        mpp.push_back({arr[i], i + 1});
    }
    sort(mpp.begin(), mpp.end(), customSort);
    for (auto & it : mpp) {
        cout << it.second << " ";
    }
    cout << endl;
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> arr(n);
        for (auto & it : arr) {
            cin >> it;
        }
        solve(arr, k);
    }
    return 0;
}