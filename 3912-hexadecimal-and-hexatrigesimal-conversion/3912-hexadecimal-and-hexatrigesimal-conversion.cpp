class Solution {
public:
    string toHex(int num) {
        stringstream ss;
        ss << hex << uppercase << num;
        return ss.str();
    }
    string toBase36(long long num) {
        if (num == 0)
            return "0";

        string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string result;

        while (num > 0) {
            int rem = num % 36;
            result = digits[rem] + result;
            num /= 36;
        }

        return result;
    }
    string concatHex36(int n) {
        string str1 = toHex(n * n);
        string str2 = toBase36(n * n * n);
        return str1 + str2;
    }
};