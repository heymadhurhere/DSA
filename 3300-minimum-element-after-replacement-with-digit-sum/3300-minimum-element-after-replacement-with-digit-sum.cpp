class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = 0;
            while (nums[i] > 0) {
                num += nums[i] % 10;
                nums[i] /= 10;
            }
            nums[i] = num;
        }
        return *min_element(nums.begin(), nums.end());
    }
};