#include <bits/stdc++.h>
using namespace std;
 
long long solve(vector<long long>& arr)
{
    int n = arr.size();
    map<long long, long long> mpp;
    for (long long i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }
    long long currHighFreq = 0;
    for (auto & it : mpp) {
        currHighFreq = max(currHighFreq, it.second);
    }
    long long opns = 0;
    while (currHighFreq < n) {
        opns++;
        if (currHighFreq * 2 <= n) {
            opns += currHighFreq;
            currHighFreq *= 2;
        }
        else {
            opns += n - currHighFreq;
            currHighFreq = n;
        }
    }
    return opns;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr) << endl;
    }
    return 0;
}