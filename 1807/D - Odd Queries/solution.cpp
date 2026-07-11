#include <bits/stdc++.h>
using namespace std;
 
void solve(vector<long long> &arr, long long l, long long r, long long k, vector<long long> &prefixSum, vector<long long> &suffixSum)
{
    long long n = arr.size();
    cout << (((prefixSum[l - 1] + suffixSum[r]) % 2 != (k * (r - l + 1)) % 2) ? "YES" : "NO") << endl;
}
 
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, q;
        cin >> n >> q;
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<long long> prefixSum(n + 1), suffixSum(n + 1);
        prefixSum[0] = 0, suffixSum[n] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            suffixSum[i] = suffixSum[i + 1] + arr[i];
        }
        for (long long i = 0; i < q; i++)
        {
            long long l, r, k;
            cin >> l >> r >> k;
            solve(arr, l, r, k, prefixSum, suffixSum);
        }
    }
    return 0;
}