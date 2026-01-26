class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        int i = 0, j = n / 2;

        int cnt = 0;
        while (i < n / 2 && j < n) {
            if (nums[i] < nums[j]) {
                cnt += 2;
                i++;
                j++;
            } else if (nums[i] >= nums[j])
                j++;
        }
        return n - cnt;
    }
};