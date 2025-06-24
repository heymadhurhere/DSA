class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> arr;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key)
                arr.push_back(i);
        }
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (curr + 1 < arr.size()) {
                if (abs(i - arr[curr + 1]) <= abs(i - arr[curr])) {
                    if (abs(i - arr[curr + 1]) <= k)
                        ans.push_back(i);
                    curr++;
                } else if (abs(i - arr[curr]) <= k)
                    ans.push_back(i);
            } else {
                if (abs(i - arr[curr]) <= k)
                    ans.push_back(i);
            }
        }
        return ans;
    }
};