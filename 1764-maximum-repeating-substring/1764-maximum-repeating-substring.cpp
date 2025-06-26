class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int cnt = 0;
        bool flag = true;
        string temp = word;
        while (flag) {
            if (sequence.find(temp) != string::npos) {
                temp += word;
                cnt++;
            } else {
                flag = false;
            }
        }
        return cnt;
    }
};