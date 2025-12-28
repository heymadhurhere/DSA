class Solution {
public:
    int bin(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n - 1;

        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (arr[mid] < 0) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return i;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            int j = bin(grid[i]);
            ans += (n - j);
        }

        return ans;
    }
};