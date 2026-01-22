class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2,
                        int k) {
        int n = technique1.size();
        long long sum = accumulate(technique1.begin(), technique1.end(), 0LL);

        vector<int> diff;
        for (int i = 0; i < n; i++) {
            diff.push_back(technique2[i] - technique1[i]);
        }

        sort(diff.rbegin(), diff.rend());

        int idx = n - k;
        for (int i = 0; i < idx; i++) {
            if (diff[i] > 0) {
                sum += diff[i];
            } else
                break;
        }
        return sum;
    }
};