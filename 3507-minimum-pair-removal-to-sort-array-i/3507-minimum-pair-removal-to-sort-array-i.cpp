class Solution {
public:
    bool isSorted(vector<int>& arr) {
        vector<int> tmp = arr;
        sort(tmp.begin(), tmp.end());
        return arr == tmp;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;

        while (!isSorted(nums)) {
            int mini = INT_MAX, idx = -1;

            int n = nums.size();
            for (int i = 0; i < n - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < mini) {
                    mini = sum;
                    idx = i;
                }
            }
            nums[idx] = mini;
            nums.erase(nums.begin() + idx + 1);
            cnt++;
        }
        return cnt;
    }
};