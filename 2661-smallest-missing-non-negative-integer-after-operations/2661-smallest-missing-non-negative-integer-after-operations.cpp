class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = ((nums[i] % value) + value) % value;
        }
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        int mini = 0, minFreq = INT_MAX;
        for (int i = 0; i < value; i++) {
            int f = mpp.count(i) ? mpp[i] : 0;
            if (f < minFreq) {
                mini = i;
                minFreq = f;
            }
        }
        return minFreq * value + mini;
    }
};