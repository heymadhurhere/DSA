class Solution {
public:
    long long countCar(vector<int>& ranks, long long mid) {
        long long cnt = 0;
        for (int i = 0; i < ranks.size(); i++) {
            cnt += (long long)sqrt((double)mid / ranks[i]);
        }
        return cnt;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        int mini = *min_element(ranks.begin(), ranks.end());
        long long maxi = 1LL * mini * cars * cars;

        // int q = cars / n;
        // int rem = cars % n;
        // long long maxi = 0;
        // for (int i = 0; i < n; i++) {
        //     maxi += 1LL * ranks[i] * q * q;
        // }
        // maxi += mini * rem * rem;

        long long l = 0, r = maxi;
        long long res = 0;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (countCar(ranks, mid) >= cars) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};