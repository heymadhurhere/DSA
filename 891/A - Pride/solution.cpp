#include <bits/stdc++.h>
 
using namespace std;
 
int32_t main() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
 
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &i : a) cin >> i; // read array a of size n
 
		int g = a[0];
		int cnt = 0; // count how many elements are already 1
		for (auto i : a) {
				g = __gcd(g, i); // gcd of the entire array
				if (i == 1) cnt++;
		}
 
		if (g > 1) { // if overall gcd > 1, it's impossible to reach all 1's
				cout << "-1
";
				return 0;
		}
 
		if (cnt) { // if there is at least one 1
				// Use the existing 1 as a seed to spread: each non-1 becomes 1 in one operation
				cout << n - cnt << '
';
				return 0;
		}
 
		int ans = 2 * n; // large initial value (upper bound placeholder)
		// Find the shortest subarray with gcd == 1. If subarray [i..j] has gcd 1,
		// it takes (j - i) operations to make a 1 inside, then (n - 1) to spread it across the array.
		for (int i = 0; i < n; i++) {
				int gc = a[i];
				for (int j = i + 1; j < n; j++) {
						gc = __gcd(gc, a[j]); // progressive gcd of a[i..j]
						if (gc == 1) { // found minimal j for this i
								ans = min(ans, (n - 1) + (j - i));
								break; // no need to extend further for this i
						}
				}
		}
 
		cout << ans << '
';
 
		return 0;
}
 
/*
Time Complexity (TC): O(n^2*log(ai))
Space Complexity (SC): O(n)
*/