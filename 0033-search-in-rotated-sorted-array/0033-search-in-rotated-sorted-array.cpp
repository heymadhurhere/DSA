class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1) {
            return (nums[0] == target) ? 0 : -1;
        }
        int l = 0, h = n - 1, p = 0;
        if (nums[0] <= nums[n - 1]) {
            p = 0;
        } else {
            while (l <= h) {
                int mid = l + (h - l) / 2;
                if (mid < n - 1 && nums[mid] > nums[mid + 1]) {
                    p = mid + 1;
                    break;
                } else if (nums[mid] < nums[l]) {
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        int s1 = 0, e1 = p - 1;
        while (s1 <= e1) {
            int mid = s1 + (e1 - s1) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                e1 = mid - 1;
            } else {
                s1 = mid + 1;
            }
        }
        int s2 = p, e2 = n - 1;
        while (s2 <= e2) {
            int mid = s2 + (e2 - s2) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                e2 = mid - 1;
            } else {
                s2 = mid + 1;
            }
        }
        return -1;
    }
};