class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cntMaj = 1, maj = nums[0];
        int cntMin = 0, mini = -1;
        int cntThird = 0, third = -1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] != maj && nums[i] != mini && nums[i] != third) {
                third = nums[i];
                cntThird = 1;
            } else if (nums[i] == maj) {
                cntMaj++;
            } else if (nums[i] == mini) {
                cntMin++;
            } else if (nums[i] == third) {
                cntThird++;
            }
            if (cntThird >= cntMin) {
                swap(cntThird, cntMin);
                swap(third, mini);
            }
            if (cntMin >= cntMaj) {
                swap(maj, mini);
                swap(cntMin, cntMaj);
            }
        }
        return (cntMin > cntMaj) ? mini : maj;
    }
};
