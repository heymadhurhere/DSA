class Solution {
public:
    int minMaxDifference(int num) {
        string temp = to_string(num);
        char large = '-1', small = '-1';
        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] != '9') {
                large = temp[i];
                break;
            }
        }
        small = temp[0];
        string maxi = temp;
        string mini = temp;
        for (int i = 0; i < temp.length(); i++) {
            if (maxi[i] == large) {
                maxi[i] = '9';
            }
            if (mini[i] == small) {
                mini[i] = '0';
            }
        }
        int maxm = stoi(maxi);
        int minm = stoi(mini);
        return (maxm - minm);
    }
};