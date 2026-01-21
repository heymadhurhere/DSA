class Solution {
public:
    int search(vector<pair<int, int>>& arr, int x, int idx) {
        int l = 0, r = idx;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid].first <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int, int>> store;
        for (int i = 0; i < n; i++) {
            store.push_back({costs[i], capacity[i]});
        }

        sort(store.begin(), store.end());

        vector<int> pref(n);
        pref[0] = store[0].second;
        for (int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], store[i].second);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (store[i].first < budget) {
                ans = max(ans, store[i].second);
            } else {
                break;
            }

            int rem = budget - store[i].first - 1;
            if (rem < 0)
                continue;
            int idx = search(store, rem, i - 1);
            if (idx != -1) {
                ans = max(ans, store[i].second + pref[idx]);
            }
        }
        return ans;

        return ans;
    }
};