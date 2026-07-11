#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int &val : arr) cin >> val;
 
        vector<int> lastPos(n + 1, -1);
        for (int i = n - 1; i >= 0; --i)
            if (lastPos[arr[i]] == -1) lastPos[arr[i]] = i;
 
        vector<char> required(n + 1, 0), inBlock(n + 1, 0);
        int reqCount = 0, segments = 0, earliestLast = n;
        vector<int> blockVals;
 
        for (int i = 0; i < n; ++i) {
            int x = arr[i];
 
            if (required[x]) {
                required[x] = 0;
                --reqCount;
            }
 
            if (!inBlock[x]) {
                inBlock[x] = 1;
                blockVals.push_back(x);
                earliestLast = min(earliestLast, lastPos[x]);
            }
 
            if (reqCount == 0 && i < earliestLast) {
                ++segments;
                for (int val : blockVals) {
                    inBlock[val] = 0;
                    required[val] = 1;
                }
                reqCount = blockVals.size();
                blockVals.clear();
                earliestLast = n;
            }
        }
 
        cout << segments + 1 << '
';
    }
 
    return 0;
}