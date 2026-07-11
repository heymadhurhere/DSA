#include <iostream>
using namespace std;
 
bool solve(int l1, int b1, int l2, int b2, int l3, int b3) {
    if (b1 == b2 && b2 == b3 && (l1 + l2 + l3 == b1)) return true;
 
    if (l1 == l2 && l2 == l3 && (b1 + b2 + b3 == l1)) return true;
 
    if (b1 == b2 && (l3 == l1 + l2) && (b3 + b1 == l3)) return true;
 
    if (l1 == l2 + l3 && b2 == b3 && b1 + b2 == l1) return true;
 
    if (l1 == l2 && (b1 + b2 == b3) && (l3 + l1 == b3)) return true;
 
    if (l2 == l3 && (b2 + b3 == b1) && (l1 + l2 == b1)) return true;
 
    return false;
}
 
int main() {
    int test;
    cin >> test;
    while (test--) {
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        if (solve(l1, b1, l2, b2, l3, b3))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}