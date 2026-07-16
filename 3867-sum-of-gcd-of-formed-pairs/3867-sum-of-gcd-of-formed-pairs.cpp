class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefMax(n);
        prefMax[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefMax[i] = max(nums[i], prefMax[i - 1]);
        }

        vector<int> prefGcd(n);
        for (int i = 0; i < n; i++) {
            prefGcd[i] = __gcd(prefMax[i], nums[i]);
        }

        sort(prefGcd.begin(), prefGcd.end());

        long long sum = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            int tmp = __gcd(prefGcd[i], prefGcd[j]);
            sum += tmp;
            i++;
            j--;
        }
        return sum;
    }
};