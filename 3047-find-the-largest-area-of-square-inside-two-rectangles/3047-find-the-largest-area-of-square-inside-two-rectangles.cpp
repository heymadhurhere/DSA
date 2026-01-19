class Solution {
public:
    bool intersect(int f_a_i, int f_b_i, int f_c_i, int f_d_i, int s_a_i,
                   int s_b_i, int s_c_i, int s_d_i, int& l, int& b) {
        int x = min(f_c_i, s_c_i) - max(f_a_i, s_a_i);
        int y = min(f_d_i, s_d_i) - max(f_b_i, s_b_i);

        if (x > 0 && y > 0) {
            l = x;
            b = y;
            return true;
        }
        return false;
    }
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        // store coordinate for each rectangle
        int n = bottomLeft.size();

        vector<pair<pair<int, int>, pair<int, int>>> loctn;

        for (int i = 0; i < n; i++) {
            int a_i = bottomLeft[i][0];
            int b_i = bottomLeft[i][1];

            int c_i = topRight[i][0];
            int d_i = topRight[i][1];

            loctn.push_back({{a_i, b_i}, {c_i, d_i}});
        }

        // iterate over all possible rectangle pairs

        // increasing the intersection of rectangles may decreade the area or
        // the area will remian constant, the area cannot increase

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int f_a_i = loctn[i].first.first;
                int f_b_i = loctn[i].first.second;
                int f_c_i = loctn[i].second.first;
                int f_d_i = loctn[i].second.second;

                int s_a_i = loctn[j].first.first;
                int s_b_i = loctn[j].first.second;
                int s_c_i = loctn[j].second.first;
                int s_d_i = loctn[j].second.second;

                int length = 0, breadth = 0;

                intersect(f_a_i, f_b_i, f_c_i, f_d_i, s_a_i, s_b_i, s_c_i,
                          s_d_i, length, breadth);

                long long area =
                    1LL * min(length, breadth) * min(length, breadth);
                ans = max(ans, area);
            }
        }
        return ans;
    }
};