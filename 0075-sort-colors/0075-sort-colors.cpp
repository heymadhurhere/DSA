class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int s = -1, m = 0, e = n;
        while (m < e) {
            if (nums[m] == 0) {
                s++;
                swap(nums[s], nums[m]);
                m++;
            } else if (nums[m] == 2) {
                e--;
                swap(nums[m], nums[e]);
            } else {
                m++;
            }
        }
    }
};