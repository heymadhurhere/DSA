class Solution {
public:
    int sum;
    vector<int> a;
    Solution(vector<int>& w) {
        for (int i = 1; i < w.size(); i++) {
            w[i] += w[i - 1];
        }
        a = w;
        sum = w.back();
    }

    int pickIndex() {
        int val = random() % sum;
        auto it = upper_bound(a.begin(), a.end(), val) - a.begin();
        return it;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */