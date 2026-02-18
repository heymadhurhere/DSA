class Solution {
public:
    string toBin(int n) {
        string tmp = "";
        while (n > 0) {
            int rem = n % 2;
            tmp += rem + '0';
            n /= 2;
        }
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }
    bool isPal(int n) {
        string tmp = toBin(n);
        int len = tmp.length();
        int l = 0, r = len - 1;
        while (l < r) {
            if (tmp[l] != tmp[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    vector<int> minOperations(vector<int>& nums) {
        vector<bool> pal(5000, false);
        for (int i = 1; i <= 5000; i++) {
            if (isPal(i))
                pal[i - 1] = true;
        }
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int idx = nums[i] - 1;
            if (pal[idx]) {
                ans.push_back(0);
                continue;
            }
            int leftDist = INT_MAX, rightDist = INT_MAX;
            for (int i = idx - 1; i >= 0; i--) {
                if (pal[i]) {
                    leftDist = idx - i;
                    break;
                }
            }
            for (int i = idx + 1; i <= 5000; i++) {
                if (pal[i]) {
                    rightDist = i - idx;
                    break;
                }
            }
            ans.push_back(min(leftDist, rightDist));
        }
        return ans;
    }
};