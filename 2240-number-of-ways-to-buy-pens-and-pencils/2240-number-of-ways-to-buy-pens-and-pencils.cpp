class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        long long lim = total / cost1;
        long long i = 0;
        while (i <= lim) {
            long long tmp = total - i * cost1;
            ans += (tmp / cost2) + 1;
            i++;
        }
        return ans;
    }
};