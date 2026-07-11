#include <bits/stdc++.h>
using namespace std;
 
int solve(vector<int>& arr) {
    int n = arr.size();
    int cntNeg = 0, cntPos = 0;
    for (auto & it : arr) {
        if (it == -1) cntNeg++;
        if (it == 1) cntPos++;
    }
    if (cntNeg == cntPos) {
        return (cntNeg % 2 == 1) ? 1 : 0;
    }
    else if (cntNeg < cntPos) {
        return (cntNeg % 2 == 1) ? 1 : 0;
    }
    else if (cntNeg > cntPos) {
        double opns = 0;
        opns += ceil((double)((cntNeg) - (cntPos)) / 2);
        cntNeg -= (int)opns;
        if (cntNeg % 2 == 1) opns++;
        return (int)opns;
    }
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