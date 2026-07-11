#include <iostream>
#include <string>
using namespace std;
 
int main(){
    string s;
    cin >> s;
    for (auto &it : s){
        if (it > '4'){
            it = '9' - it + '0';
        }
    }
    if (s.front() == '0'){
        s.front() = '9';    
    }
    cout << s << endl;
    return 0;
}