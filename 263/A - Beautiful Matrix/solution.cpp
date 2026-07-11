#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int arr[5][5];
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cin >> arr[i][j];
        }
    }
 
    int row = 0, col = 0;
    bool found = false;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (arr[i][j] == 1){
                row = i;
                col = j;
                found = true;
                break;
            }
        }
        if (found){
            break;
        }
    }
    int ans = abs(2 - row) + abs(2 - col);
    cout << ans;
    return 0;
}