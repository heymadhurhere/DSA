#include <bits/stdc++.h>
using namespace std;
vector<int> solve(string s) {
    int year = stoi(s);
    int root = sqrt(year);
    vector<int> ans;
    if (root * root == year) {
        ans.push_back(0);
        ans.push_back(root);
    }
    else {
        ans.push_back(-1);
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int> res = solve(s);
        if (res.size() == 1 && res[0] == -1) {
            cout << -1 << endl;
        } else {
            cout << res[0] << " " << res[1] << endl;
        }
    }
    return 0;
}