class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        
        int i = 0;
        
        while (i < n) {
            if (!st.empty()) {
                if (st.top() < 0 && arr[i] < 0) {
                    st.push(arr[i]);
                    i++;
                }
                else if (st.top() > 0 && arr[i] > 0) {
                    st.push(arr[i]);
                    i++;
                } else if (st.top() > 0 && arr[i] < 0) {
                    if (abs(st.top()) > abs(arr[i])) {
                        i++;
                    } else if (abs(st.top()) < abs(arr[i])) {
                        st.pop();
                    } else if (abs(st.top()) == abs(arr[i])) {
                        st.pop();
                        i++;
                    }
                } else if (st.top() < 0 && arr[i] > 0) {
                    st.push(arr[i]);
                    i++;
                }
            } else {
                st.push(arr[i]);
                i++;
            }
        }
        
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};