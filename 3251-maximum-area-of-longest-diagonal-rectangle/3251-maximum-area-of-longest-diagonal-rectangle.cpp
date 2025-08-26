class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        int diag = 0;
        for (int i = 0; i < dimensions.size(); i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            int tmp = l * l + w * w;
            if (tmp > diag) {
                diag = tmp;
                ans = l * w;
            } else if (tmp == diag) {
                ans = max(ans, l * w);
            }
        }
        return ans;
    }
};