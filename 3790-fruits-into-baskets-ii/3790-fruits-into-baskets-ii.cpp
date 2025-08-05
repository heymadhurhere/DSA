class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            bool plced = false;
            for (int j = 0; j < n; j++) {
                if (baskets[j] >= fruits[i]) {
                    plced = true;
                    baskets[j] = 0;
                    break;
                }
            }
            if (!plced) cnt++;
        }
        return cnt;
    }
};