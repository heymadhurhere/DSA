class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int cnt = 0;
        int i = 0, j = n / 2;

        while (i < n / 2 && j < n) {
            if (nums[i] * 2 <= nums[j]) {
                cnt += 2;
                i++;
                j++;
            } else if (2 * nums[i] > nums[j]) {
                j++;
            }
        }
        return cnt;
    }
};