class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 3 != 0)
            return false;
        int tmp = sum / 3;
        int curr = 0, cnt = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            curr += arr[i];
            if (curr == tmp) {
                curr = 0;
                cnt++;
                if (cnt == 2)
                    return true;
            }
        }
        return false;
    }
};