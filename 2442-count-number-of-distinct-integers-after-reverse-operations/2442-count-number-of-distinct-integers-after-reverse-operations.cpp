class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (auto it : nums) {
            st.insert(it);
        }
        for (auto it : nums) {
            int num = it;
            string str = to_string(num);
            reverse(str.begin(), str.end());
            num = stoi(str);
            st.insert(num);
        }
        return st.size();
    }
};