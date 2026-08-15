class Solution {
public:
    int numRabbits(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        int i = 0;
        int ans = 0;
        while (i < n) {
            int tmp = a[i];
            int j = i;
            while (j < n && j < i + tmp + 1 && a[j] == tmp) {
                j++;
            }
            ans += tmp + 1;
            i = j;
        }
        return ans;
    }
};