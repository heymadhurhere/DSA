class Solution {
public:
    bool isIncreasing(vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1])
                return false;
        }
        return true;
    }
    bool isDecreasing(vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1])
                return false;
        }
        return true;
    }

    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();
        vector<int> arr1 = arr, brr1 = brr;

        long long ans2 = 0;
        for (int i = 0; i < n; i++) {
            ans2 += abs(arr[i] - brr[i]);
        }

        bool arrInc = isIncreasing(arr);
        bool arrDec = isDecreasing(arr);
        bool brrInc = isIncreasing(brr);
        bool brrDec = isDecreasing(brr);

        long long ans = 0;

        if (!((arrInc && brrInc) || (arrDec && brrDec))) {
            sort(arr1.begin(), arr1.end());
            sort(brr1.begin(), brr1.end());
            ans += k;
        }

        for (int i = 0; i < n; i++) {
            ans += abs(arr1[i] - brr1[i]);
        }

        return min(ans, ans2);
    }
};