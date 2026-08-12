class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();

        double ref = ((double)a) / ((double)b);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int e = 0, o = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0)
                    e++;
                if (nums[j] % 2 != 0)
                    o++;

                if (o > 0 && ((double)e) / ((double)o) <= ref)
                    ans++;
            }
        }
        return ans;
    }
};