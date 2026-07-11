#include <bits/stdc++.h>
using namespace std;
 
void solve(vector<int>& arr) {
    int n = arr.size();
    int a = 0, b = 0;
    bool flag = false;
    for (int i = 0; i < n && !flag; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                a = arr[i];
                b = arr[j];
                flag = true;
                break;
            }
        }
    }
    if (!flag) {
        cout << "NO" << endl;
        return;
    } else {
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << a << " " << b << endl;
        return;
    }
 
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
        for (auto & it : arr) {
            cin >> it;
        }
        solve(arr);
    }
}