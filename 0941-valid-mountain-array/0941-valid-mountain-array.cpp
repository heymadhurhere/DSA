class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;
        bool inc = false, dec = false;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == arr[i + 1])
                return false;
            if (arr[i] < arr[i + 1]) {
                if (dec)
                    return false;
                inc = true;
            }
            if (arr[i] > arr[i + 1]) {
                if (!inc)
                    return false;
                dec = true;
            }
        }
        if (inc && dec)
            return true;
        return false;
    }
};