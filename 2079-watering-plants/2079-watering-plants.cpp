class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();

        int ans = 1;
        int cap = capacity;
        cap -= plants[0];
        int i = 0;
        while (i < n - 1) {
            if (cap >= plants[i + 1]) {
                ans++;
            } else {
                ans += (i + 1) * 2 + 1;
                cap = capacity;
            }
            cap -= plants[i + 1];
            i++;
        }
        return ans;
    }
};