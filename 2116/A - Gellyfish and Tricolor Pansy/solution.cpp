#include <bits/stdc++.h>
using namespace std;
 
string solve(int a, int b, int c, int d)
{
	if (b <= a && b <= c) {
		return "Gellyfish";
	}
	else if (a < d) {
		return "Flower";
	}
	else if (d <= c) {
		return "Gellyfish";
	}
	return "Flower";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << solve(a, b, c, d) << '
';
	}
 
	return 0;
}