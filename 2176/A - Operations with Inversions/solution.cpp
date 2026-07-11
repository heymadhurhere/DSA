#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using vec = vector<ll>;
 
ll countRemovals(vec &arr) {
    ll n = arr.size();
    ll operations = 0;
 
    ll lead = 0;
    ll scan = 1;
 
    while (scan < n) {
        if (arr[lead] > arr[scan]) {
            operations++;
            scan++;
        } else {
            lead = scan;
            scan++;
        }
    }
 
    return operations;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll testCases;
    cin >> testCases;
 
    while (testCases--) {
        ll size;
        cin >> size;
 
        vec elements(size);
        for (ll i = 0; i < size; i++) {
            cin >> elements[i];
        }
 
        cout << countRemovals(elements) << "
";
    }
 
    return 0;
}