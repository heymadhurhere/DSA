class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // linear time + (m + n) space
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        if (n == 0) {
            return;
        }
        int i = 0, j = 0;
        vector<int> temp;
        temp.reserve(m + n);
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            } else {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        while (i < m) {
            temp.push_back(nums1[i]);
            i++;
        }
        while (j < n) {
            temp.push_back(nums2[j]);
            j++;
        }
        nums1 = temp;
        // constant space + (m + n)log(m + n) time use STL
    }
};