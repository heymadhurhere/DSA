class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (nums1[n1 - 1] > nums2[0]) {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < n1; i++) {
            int l = 0, h = n2 - 1;
            while (l <= h) {
                int mid = l + (h - l) / 2;
                if (nums2[mid] >= nums1[i]) {
                    ans = max(ans, mid - i);
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
        }
        return ans;
    }
};