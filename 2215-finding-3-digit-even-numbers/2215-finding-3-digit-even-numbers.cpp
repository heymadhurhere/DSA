class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> store(10, 0);
        int n = digits.size();
        for (int i = 0; i < n; i++) {
            store[digits[i]]++;
        }
        for (int i = 100; i < 999; i += 2) {
            int num = i;
            int to_push = i;
            int unit = num % 10;
            num /= 10;
            int tens = num % 10;
            num /= 10;
            int hundreds = num % 10;
            num /= 10;
            vector<int> freq = store;
            if (freq[unit]-- > 0 && freq[tens]-- > 0 && freq[hundreds]-- > 0) {
                ans.push_back(to_push);
            }
        }
        return ans;
    }
};