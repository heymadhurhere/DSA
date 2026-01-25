class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 == 1)
            return {};
        vector<long long> ans;

        long long i = 0, tmp = 2;
        while (tmp + i <= finalSum) {
            i += tmp;
            ans.push_back(tmp);
            tmp += 2;
        }
        long long left = finalSum - i;
        if (left > 0)
            ans.back() += left;
        // ans.push_back(left);
        return ans;
    }
};