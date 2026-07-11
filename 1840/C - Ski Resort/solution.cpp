#include <bits/stdc++.h>
using namespace std;
 
long long natSum(long long n) {
    return (n * (n + 1)) / 2;
}
 
void solve(vector<long long>& arr, long long k, long long q) {
    long long n = arr.size();
    long long i = 0, j = 0;
    vector<long long> temp;
    while (j < n) {
        int cnt = 0;
        while (j < n && arr[j] <= q) {
            cnt++;
            j++;
        }
        if (cnt != 0) {
            temp.push_back(cnt);
        }
        j++;
    }
    long long sum = 0;
    for (auto &it : temp) {
        if (it >= k) {
            sum += natSum(it - k + 1);
        }
    }
    cout << sum << endl;
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        long long n, k, q;
        cin >> n >> k >> q;
        vector<long long> arr(n);
        for (auto & it : arr) {
            cin >> it;
        }
        solve(arr, k, q);
    }
    return 0;
}