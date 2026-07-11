#include <iostream>
using namespace std;
 
string solve(int a, int b, int c) {
    if (c % 2 == 1) {
        return (a >= b) ? "First" : "Second";
    }
    else {
        return (a > b) ? "First" : "Second";
    }
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << endl;
    }
    return 0;
}