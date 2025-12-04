class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.length();
        vector<int> cars;
        for (int i = 0; i < n; i++) {
            if (directions[i] == 'R')
                cars.push_back(1);
            else if (directions[i] == 'L')
                cars.push_back(-1);
            else if (directions[i] == 'S')
                cars.push_back(0);
        }
        int cnt = 0;
        int i = 0, j = n - 1;

        while (i < n && cars[i] == -1)
            ++i;
        while (j >= 0 && cars[j] == 1)
            --j;
        if (i > j)
            return 0;

        

        for (int l = i; l <= j; l++) {
            if (cars[l] != 0)
                cnt++;
        }
        return cnt;
    }
};