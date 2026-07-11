#include <iostream>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
 
    int X = 0;
 
    for (int i = 0; i < n; i++)
    {
        string st;
        cin >> st;
 
        if (st == "++X" || st == "X++")
        {
            X += 1;
        }
        else if (st == "--X" || st == "X--")
        {
            X -= 1;
        }
    }
    cout << X << endl;
    return 0;
}