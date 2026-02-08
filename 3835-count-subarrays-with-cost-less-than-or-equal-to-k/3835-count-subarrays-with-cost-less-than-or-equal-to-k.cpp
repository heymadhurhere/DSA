class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        multiset<int> ms;
        long long ans = 0;
        int l = 0;
        for (int i = 0; i < n; i++) {
            ms.insert(nums[i]);
            while (!ms.empty()) {
                long long mini = *ms.begin();
                long long maxi = *ms.rbegin();
                if ((maxi - mini) * (i - l + 1) <= k)
                    break;
                ms.erase(ms.find(nums[l]));
                l++;
            }
            ans += (i - l + 1);
        }
        return ans;
    }
};