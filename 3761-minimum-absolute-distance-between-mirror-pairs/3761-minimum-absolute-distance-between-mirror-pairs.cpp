class Solution {
public:
    // int transform(int n) {
    //     while (n % 10 == 0) {
    //         n /= 10;
    //     }
    //     return n;
    // }
    int reverse(int n) {
        int ans = 0;
        while (n > 0) {
            int rem = n % 10;
            ans = ans * 10 + rem;
            n /= 10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> mpp; // number -> [indices]
        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        bool found = false;
        for (int i = 0; i < n; i++) {
            int key = reverse(nums[i]);
            if (mpp.find(key) != mpp.end()) {
                vector<int> tmp = mpp[key];
                for (int j = 0; j < tmp.size(); j++) {
                    if (tmp[j] > i) {
                        found = true;
                        ans = min(ans, abs(tmp[j] - i));
                        if (ans == 1) return ans;
                    }
                }
            }
        }
        return found == false ? -1 : ans;
    }
};