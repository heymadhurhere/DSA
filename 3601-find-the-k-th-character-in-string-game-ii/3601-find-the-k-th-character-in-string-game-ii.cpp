class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long len = 1;
        int opns = 0;
        while (len < k) {
            len *= 2;
            opns++;
        }
        k--;
        int ch = 0;
        for (int i = opns - 1; i >= 0; i--) {
            if (k >= len / 2) {
                if (operations[i] == 1) {
                    ch++;
                }
                k -= len / 2;
            }
            len /= 2;
        }
        return (ch % 26 + 'a');
    }
};