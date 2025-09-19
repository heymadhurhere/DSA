class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefMax(n);
        prefMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], height[i]);
        }
        vector<int> suffMax(n);
        suffMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMax[i] = max(suffMax[i + 1], height[i]);
        }
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (height[i] < prefMax[i] && height[i] < suffMax[i]) {
                total += min(suffMax[i], prefMax[i]) - height[i];
            }
        }
        return total;
    }
};