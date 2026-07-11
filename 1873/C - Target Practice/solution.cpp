#include <bits/stdc++.h>
using namespace std;
 
int solve(vector<vector<char>>& arr) {
   int pts = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++){
            if (arr[i][j] == 'X') {
                int r = i, c = j;
                if (r == 0 || r == 9 || c == 0 || c == 9) {
                    pts += 1;
                }
                else if (r == 1 || r == 8 || c == 1 || c == 8) {
                    pts += 2;
                }
                else if (r == 2 || r == 7 || c == 2 || c == 7) {
                    pts += 3;
                }
                else if (r == 3 || r == 6 || c == 3 || c == 6) {
                    pts += 4;
                }
                else if (r == 4 || c == 4 || r == 5 || c == 5) {
                    pts += 5;
                }
            }  
        }
    }
    return pts;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<vector<char>> arr(10, vector<char>(10, '.'));
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cin >> arr[i][j];
            }
        }
        cout << solve(arr) << endl;
    }
    return 0;   
}