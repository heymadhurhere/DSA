    #include <bits/stdc++.h>
    using namespace std;
 
    int solve (vector<int>& arr) {
        int n = arr.size();
        if (n == 1) {
            if (arr[0] == 0) return 1;
            return 0;
        }
        int i = 0;
        int j = 0;
        int maxi = INT_MIN;
        while (j < n) {
            if (arr[j] == 0) {
                j++;
            }
            else if (arr[j] == 1) {
                maxi = max(maxi, j - i);
                j++;
                i = j;
            }
        }
        maxi = max(maxi, j - i);
        return maxi;
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
            cout << solve(arr) << endl;
        }
        return 0;
    }