class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int cnt = 0;
        int n = plants.size();
        int i = 0, j = n - 1;
        int capA = capacityA, capB = capacityB;

        while (i < j) {
            if (capA < plants[i]) {
                cnt++;
                capA = capacityA;
            }

            if (capB < plants[j]) {
                cnt++;
                capB = capacityB;
            }
            capA -= plants[i];
            capB -= plants[j];
            i++;
            j--;
        }

        // same position case
        if (n % 2 != 0) {
            capA = max(capA, capB);
            if (capA < plants[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};