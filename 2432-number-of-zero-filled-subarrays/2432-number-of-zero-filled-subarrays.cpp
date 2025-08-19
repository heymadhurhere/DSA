class Solution {
public:
    long long natSum(int n) {
        long long res = 0;
        res = (((long long)n) * ((long long)n + 1)) / 2;
        return res;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        vector<long long> tmp;
        int n = nums.size();
        int i = 0, j = 0;
        while (j < n) {
            if (nums[i] == 0 && nums[j] == 0 && j + 1 >= n) {
                tmp.push_back(j - i + 1);
                break;
            }
            if (nums[i] == 0 && nums[j] == 0) {
                j++;
            }
            if (nums[i] == 0 && nums[j] != 0) {
                tmp.push_back(j - i);
                i = j;
            }
            if (nums[i] != 0 && nums[j] != 0) {
                i++;
                j++;
            }
        }
        long long ans = 0;
        for (int i = 0; i < tmp.size(); i++) {
            ans += natSum(tmp[i]);
        }
        return ans;
    }
};