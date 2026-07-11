#include <iostream>
using namespace std;
 
int main() {
    int tc;
    cin >> tc;
 
    while (tc--) {
        int n;
        cin >> n;
 
        cout << 2 * n - 3 << endl;
 
        cout << 1 << " " << 2 << " " << n << endl;
 
        for (int i = 2; i <= n - 2; i++) {
            cout << i << " " << 1 << " " << i << endl;
            cout << i << " " << i + 1 << " " << n << endl;
        }
 
        cout << n - 1 << " " << 1 << " " << n - 1 << endl;
        cout << n << " " << 1 << " " << n << endl;
    }
 
    return 0;
}