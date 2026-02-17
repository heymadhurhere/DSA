class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long a = 0;
        for (int i = 0; i < n; i++) {
            a ^= nums[i];
        }
        int pos = 0;
        while (!(a & 1)) {
            a >>= 1;
            pos++;
        }
        long long b = 0, c = 0;
        for (int i = 0; i < n; i++) {
            long long tmp = nums[i];
            tmp >>= pos;
            if (tmp & 1)
                b ^= nums[i];
            else
                c ^= nums[i];
        }
        return {(int)b, (int)c};
    }
};