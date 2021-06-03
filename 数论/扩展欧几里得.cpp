#include<bits/stdc++.h>
using namespace std;
void extend_gcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1, y = 0;
		return;
	}
	extend_gcd(b, a%b, x, y);
	int tmp = x;
	x = y;
	y = tmp - (a / b)*y;
}
int gcd(int x,int y) {
	return y == 0 ? x : gcd(y, x%y);
}
//求逆元
int main()
{
	int a,b,m,n;
	while (cin >> a >> m) {
		int x, y;
		int d = gcd(a, m);
		if (d!=1) {
			cout << "none!" << endl; continue;
		}
		extend_gcd(a, m, x, y);
		cout << (m + x % m) % m << endl;
	}
}