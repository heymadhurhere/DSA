#include <bits/stdc++.h>
using namespace std;
int findClosestEven(vector<int>& arr) {
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) {
            ans = i;
            break;
        }
    }
    return ans;
}
int findClosestOdd(vector<int>& arr) {
    int ans = 0;
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (arr[i] % 2 == 1) {
            ans = i;
            break;
        }
    }
    return ans;
}
 
int findClosestOdd1(vector<int>& arr) {
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 1) {
            ans = i;
            break;
        }
    }
    return ans;
}
 
int findClosestEven1(vector<int>& arr) {
    int ans = 0;
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (arr[i] % 2 == 0) {
            ans = i;
            break;
        }
    }
    return ans;
}
 
int solve(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int ans = arr[0] + arr[n - 1];
    if (ans % 2 == 0) {
        return 0;
    }
    if (arr[0] % 2 == 1) {
        int closestEven = findClosestEven(arr);
        int closestOdd = findClosestOdd(arr);
        return min(closestEven, n - 1 - closestOdd);
    }
    return min(findClosestOdd1(arr), n - 1 - findClosestEven1(arr));
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr) << '
';
    }
    return 0;
}