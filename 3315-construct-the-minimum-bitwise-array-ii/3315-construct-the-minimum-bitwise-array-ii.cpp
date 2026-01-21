class Solution {
public:
    int solve(int n) {
        // in the binary form, find the first 0 from the RHS
        // then convert the next set bit to the right of that 0 to 0
        // it is our number
        // if we cannot find any 0 in the binary form, then answer is log2(num +
        // 1) - 1

        int len = (int)(log2(n));
        string bin = bitset<64>(n).to_string().substr(64 - len - 1);

        bool fnd = false;
        int idx = -1;

        int size = bin.length();
        int i = size - 1;
        while (i >= 0) {
            if (bin[i] == '0') {
                fnd = true;
                idx = i;
                break;
            } else
                i--;
        }
        if (!fnd) {
            int ans = (1 << (int)log2(n)) - 1;
            return ans;
        }
        bin[idx + 1] = '0';
        int ans = stoi(bin, 0, 2);
        return ans;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 2) {
                ans.push_back(-1);
                continue;
            }
            int tmp = solve(nums[i]);
            ans.push_back(tmp);
        }
        return ans;
    }
};