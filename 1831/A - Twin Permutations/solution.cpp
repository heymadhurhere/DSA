    #include <bits/stdc++.h>
    using namespace std;
 
    void solve(vector<int>& arr, int n) {
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = n - arr[i] + 1;
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
 
    int main () {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vector<int> arr(n);
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            solve(arr, n);
        }
        return 0;
    }