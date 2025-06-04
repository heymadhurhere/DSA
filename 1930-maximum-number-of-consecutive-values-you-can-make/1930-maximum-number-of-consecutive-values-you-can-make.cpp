class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int sum = 0;
        for (auto it : coins) {
            if (it <= sum + 1)
                sum += it;
            else
                break;
        }
        return sum + 1;
    }
};