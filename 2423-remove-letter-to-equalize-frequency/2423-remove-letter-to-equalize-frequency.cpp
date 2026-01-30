class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> mpp;
        for (auto& it : word) {
            mpp[it]++;
        }
        if (mpp.size() == word.length())
            return true;
        if (mpp.size() == 1)
            return true;
        unordered_map<int, int> freqCnt;
        for (auto& it : mpp) {
            freqCnt[it.second]++;
        }
        if (freqCnt.size() > 2)
            return false;

        if (freqCnt.size() == 1) {
            int f = freqCnt.begin()->first;
            int c = freqCnt.begin()->second;
            return (f == 1 || c == 1);
        }

        auto it = freqCnt.begin();
        int f1 = it->first, c1 = it->second;
        it++;
        int f2 = it->first, c2 = it->second;

        if (f1 > f2) {
            swap(f1, f2);
            swap(c1, c2);
        }

        if (f1 == 1 && c1 == 1)
            return true;

        if (f2 - f1 == 1 && c2 == 1)
            return true;
        return false;
    }
};