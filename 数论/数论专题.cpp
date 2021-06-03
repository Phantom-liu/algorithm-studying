#include<bits/stdc++.h>
using namespace std;
//∑(n/i) 整除分块
int sum1(int n) {
	int sum = 0;
	for (int i = 1, r = 0,s=0; i <= n; i = r + 1) {
		r = n / (n / i);
		sum += (r-s) * (n / i);
		s = r;
	}
	return sum;
}
int main()
{
	cout << sum1(30);
}