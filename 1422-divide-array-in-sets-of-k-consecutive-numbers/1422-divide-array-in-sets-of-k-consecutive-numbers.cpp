class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0){
            return false;
        }

        sort(nums.begin(), nums.end());

        map<int, int> mpp;
        for (int &num : nums){
            mpp[num]++;
        }

        while (!mpp.empty()){
            int curr = mpp.begin()->first;

            for (int i = 0; i < k; i++){
                if(mpp[curr + i] == 0){
                    return false;
                }

                mpp[curr + i]--;
                if (mpp[curr + i] < 1){
                    mpp.erase(curr + i);
                }
            }
        }
            return true;
    }
};