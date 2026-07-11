#include <bits/stdc++.h>
using namespace std;
 
// void solve(string &s, int k)
// {
//     int n = s.size();
//     int one = 0;
//     for (auto &it : s)
//     {
//         if (it == '1')
//             one++;
//     }
//     if (one <= k)
//     {
//         cout << "Alice" << endl;
//         return;
//     }
 
//     if (2 * k <= n)
//     {
//         cout << "Bob" << endl;
//         return;
//     }
//     bool found = false;
//     int zero = 0;
//     for (auto &it : s)
//     {
//         if (it == '0')
//             zero++;
//         else
//             zero = 0;
//         if (zero >= k)
//         {
//             found = true;
//             break;
//         }
//     }
//     if (found)
//     {
//         cout << "Bob" << endl;
//         return;
//     }
//     cout << "Alice" << endl;
//     return;
// }
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> sec_el;
        long long firstMin = LLONG_MAX;
        for (long long i = 0; i < n; i++) {
            long long m;
            cin >> m;
            vector<long long> arr(m);
            for (auto & it : arr) {
                cin >> it;
            }
            sort(arr.begin(), arr.end());
            firstMin = min(firstMin, arr[0]);
            sec_el.push_back(arr[1]);
        }
        sort(sec_el.begin(), sec_el.end());
        long long sec_el_sum = accumulate(sec_el.begin(), sec_el.end(), 0LL);
        long long low_sec_el = sec_el[0];
        cout << firstMin + sec_el_sum - low_sec_el << endl;
    }
    return 0;
}