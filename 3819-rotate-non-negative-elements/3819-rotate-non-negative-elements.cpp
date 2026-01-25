class Solution {
public:
    void leftRotate(vector<int>& v, int k) {
        int n = v.size();
        if (n == 0) return;
        k %= n;
        rotate(v.begin(), v.begin() + k, v.end());
    }
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>tmp;
        for (auto& it : nums) {
            if (it >= 0) {
                tmp.push_back(it);
            }
        }

        if (!tmp.empty()) {
            k %= tmp.size();
            leftRotate(tmp, k);
        }
        vector<int> ans(n);
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                ans[i] = nums[i];
            } else {
                ans[i] = tmp[idx++];
            }
        }
        return ans;
        
        
    }
};