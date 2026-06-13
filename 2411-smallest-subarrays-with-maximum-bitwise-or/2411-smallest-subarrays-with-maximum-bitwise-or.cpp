class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        // 32 bit number
        // for each bit of number starting from right to left, search the first bit which is set for the number after it and then find the distance between that number and present number, it will be the answer for current number

        int n = nums.size();
        vector<int> ans(n);
        vector<int> last(32, -1);
        
        for (int i = n - 1; i >= 0; i--) {
            for (int b = 0; b < 32; b++) {
                if (nums[i] & (1 << b)) {
                    last[b] = i;
                }
            }
            int far = i;

            for (int b = 0; b < 32; b++) {
                if (last[b] != -1) {
                    far = max(far, last[b]);
                }
            }
            ans[i] = far - i + 1;
        }
        return ans;
    }
};