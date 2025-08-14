class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int temp = 0;
        int n = num.length();
        for (int i = 1; i < n - 1; i++) {
            if (num[i] == num[i - 1] && num[i] == num[i + 1]) {
                if (num[i] - '0' >= temp) {
                    temp = num[i] - '0';
                    string s = num.substr(i - 1, 3);
                    ans = s;
                }
            }
        }
        return ans;
    }
};