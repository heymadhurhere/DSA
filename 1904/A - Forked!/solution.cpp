#include <bits/stdc++.h>
using namespace std;
 
long long solve(long long a, long long b, long long xk, long long yk, long long xq, long long yq) {
    map<pair<int, int>, int> mpp;
    set<pair<int, int>> moves = {
    {a, b}, {a, -b}, {-a, b}, {-a, -b},
    {b, a}, {b, -a}, {-b, a}, {-b, -a}
};
    // king
    for (auto it : moves) {
        int dx = it.first;
        int dy = it.second;
        mpp[{xk + dx, yk + dy}]++;
    }
 
    // queen
   for (auto it : moves) {
        int dx = it.first;
        int dy = it.second;
        mpp[{xq + dx, yq + dy}]++;
    }
 
    long long cnt = 0;
    for (auto it : mpp) {
        if (it.second == 2) cnt++;
    }
    return cnt;
}
 
int main () {
    long long t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long xk, yk;
        cin >> xk >> yk;
        long long xq, yq;
        cin >> xq >> yq;
        cout << solve(a, b, xk, yk, xq, yq) << endl;
    }
    return 0;
}