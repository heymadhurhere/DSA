class Solution {
public:
    string decToBin(int n) {
        string ans = "";
        while (n > 0) {
            int num = n % 2;
            ans.push_back(num + '0');
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        int len = ans.length();
        while (len < 32) {
            ans = '0' + ans;
            len++;
        }
        return ans;
    }
    int reverseBits(int n) {
        string bin = decToBin(n);
        reverse(bin.begin(), bin.end());
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans = ans * 2 + (bin[i] - '0');
        }
        return ans;
    }
};