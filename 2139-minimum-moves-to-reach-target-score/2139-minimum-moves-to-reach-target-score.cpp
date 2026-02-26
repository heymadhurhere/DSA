class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt = 0;
        while (target != 1 && maxDoubles > 0) {
            if (target % 2 == 0) {
                target /= 2;
                maxDoubles--;
                cnt++;
            } else {
                target -= 1;
                cnt++;
            }
        }
        return cnt + (target - 1);
    }
};