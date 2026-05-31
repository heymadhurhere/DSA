class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int n = asteroids.size();

        long long M = mass;

        for (int i = 0; i < n; i++) {
            if (M < asteroids[i])
                return false;
            M += asteroids[i];
        }
        return true;
    }
};