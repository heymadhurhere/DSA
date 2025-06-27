class Solution {
public:
    unordered_map<string, vector<int>> mpp;
    vector<int> diffWaysToCompute(string expression) {
        if (mpp.find(expression) != mpp.end()) {
            return mpp[expression];
        }
        vector<int> ans;
        for (int i = 0; i < expression.size(); i++) {
            char opn = expression[i];
            if (opn == '+' || opn == '-' || opn == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (auto itl : left) {
                    for (auto itr : right) {
                        if (opn == '+')
                            ans.push_back(itl + itr);
                        else if (opn == '-')
                            ans.push_back(itl - itr);
                        else if (opn == '*')
                            ans.push_back(itl * itr);
                    }
                }
            }
        }
        if (ans.empty())
            ans.push_back(stoi(expression));
        mpp[expression] = ans;
        return ans;
    }
};