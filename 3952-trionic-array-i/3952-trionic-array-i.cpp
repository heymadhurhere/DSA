class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        vector<int> check;
        int n = nums.size();
        if (n == 3)
            return false;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == nums[i - 1])
                return false;
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                check.push_back(1);
            }
            if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
                check.push_back(0);
            }
        }
        if (nums[n - 1] <= nums[n - 2]) return false;
        if (nums[n - 1] > nums[n - 2])
            check.push_back(1);
        if (check.size() < 3)
            return false;
        if (check.size() == 3) {
            if (check[0] == 1 && check[1] == 0 && check[2] == 1)
                return true;
        }
        if (check.size() == 4) {
            if (check[0] == 1 && check[1] == 0 && check[2] == 1 &&
                check[3] == 1)
                return true;
        }
        return false;
    }
};