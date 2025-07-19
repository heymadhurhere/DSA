class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> p;
        for (auto& it : arr) {
            p.push_back({__builtin_popcount(it), it});
        }
        sort(begin(p), end(p));
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = p[i].second;
        }
        return arr;
    }
};