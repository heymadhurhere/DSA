class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return (a[1] - a[0]) > (b[1] - b[0]);
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int energy = 0;

        sort(tasks.begin(), tasks.end(), cmp);

        for (auto& it : tasks) {
            energy += it[0];
        }

        int tmp = energy;
        for (auto& it : tasks) {
            if (tmp < it[1]) {
                energy += it[1] - tmp;
                tmp = it[1];
            }
            tmp -= it[0];
        }

        return energy;
    }
};