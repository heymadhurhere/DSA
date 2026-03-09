class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<char> tmp = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        vector<string> seq;
        for (int size = 2; size <= 9; size++) {
            string str = "";
            for (int i = 0; i < size; i++) {
                str += tmp[i];
            }
            seq.push_back(str);
            for (int j = size; j < tmp.size(); j++) {
                str = str.substr(1);
                str += tmp[j];
                seq.push_back(str);
            }
        }

        vector<int> store;
        for (int i = 0; i < seq.size(); i++) {
            int num = stoi(seq[i]);
            store.push_back(num);
        }
        vector<int> ans;
        int i = 0, j = store.size() - 1;
        while (i < store.size()) {
            if (store[i] >= low) {
                break;
            }
            i++;
        }
        while (j >= 0) {
            if (store[j] <= high)
                break;
            j--;
        }
        for (int ptr = i; ptr <= j; ptr++) {
            ans.push_back(store[ptr]);
        }
        return ans;
    }
};