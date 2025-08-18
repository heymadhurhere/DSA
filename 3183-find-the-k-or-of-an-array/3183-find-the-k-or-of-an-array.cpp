class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<string> tmp;
        for (int i = 0; i < n; i++) {
            string binary = bitset<32>(nums[i]).to_string();
            tmp.push_back(binary);
        }
        string ans = "";
        for (int j = 0; j < 32; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (tmp[i][j] == '1')
                    cnt++;
            }
            if (cnt >= k)
                ans += "1";
            else
                ans += "0";
        }
        int res = stoi(ans, NULL, 2);
        return res;
    }
};