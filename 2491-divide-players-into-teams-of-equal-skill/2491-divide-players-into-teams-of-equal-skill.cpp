class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(begin(skill), end(skill));
        int n = skill.size();
        int i = 0, j = n - 1;
        int sum = skill[i] + skill[j];
        long long ans = 0;
        while (i < j) {
            if (skill[i] + skill[j] != sum)
                return -1;
            else {
                ans += skill[i] * skill[j];
                i++;
                j--;
            }
        }
        return ans;
    }
};