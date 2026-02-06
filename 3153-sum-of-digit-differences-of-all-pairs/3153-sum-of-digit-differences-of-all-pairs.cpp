class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        string s = to_string(nums[0]);
        int len = s.length();
        vector<vector<int>> vec(len, vector<int>(10, 0));
        for (int i = 0; i < n; i++) {
            string tmp = to_string(nums[i]);
            for (int j = 0; j < len; j++) {
                int num = tmp[j] - '0';
                vec[j][num]++;
            }
        }

        long long ans = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < 10; j++) {
                long long pres = vec[i][j];
                long long tmp = 0;
                for (int k = j + 1; k < 10; k++) {
                    tmp += pres * vec[i][k];
                }
                ans += tmp;
            }
        }
        return ans;
    }
};