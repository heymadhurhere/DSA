class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for (int x : nums) {
            totalSum += x;
        }

        vector<int> answer(n);
        int leftSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum -= nums[i];
            int rightSum = totalSum;
            answer[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }

        return answer;
    }
};