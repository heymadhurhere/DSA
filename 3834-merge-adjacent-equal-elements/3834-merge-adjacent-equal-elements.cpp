class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;
        int n = nums.size();
        for (auto& it : nums) {
            if (st.empty())
                st.push(it);
            else if (st.top() == it) {
                long long tmp = st.top();
                st.pop();
                long long sum = tmp + it;
                while (!st.empty() && st.top() == sum) {
                    sum += st.top();
                    st.pop();
                }
                st.push(sum);
            } else {
                st.push(it);
            }
        }
        vector<long long> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};