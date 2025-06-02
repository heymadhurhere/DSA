class Solution {
public:
    bool isPrime(long long n) {
        if (n == 1)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * 1ll * i <= n; i += 6) {
            if (n % i == 0 || (n % (i + 2)) == 0)
                return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        vector<long long> arr;
        for (int i = 0; i < s.length(); i++) {
            long long num = 0;
            for (int j = i; j < s.length(); j++) {
                num = num * 10 + (s[j] - '0');
                if (isPrime(num)) {
                    arr.push_back(num);
                }
            }
        }
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        int m = arr.size();
        long long ans = 0;
        if (m < 3) {
            ans = accumulate(arr.begin(), arr.end(), 0);
            return ans;
        }
        return arr[m - 1] + arr[m - 2] + arr[m - 3];
    }
};