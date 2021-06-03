#include<bits/stdc++.h>
using namespace std;
//奇异局势（Beatty定理） 对于奇异局势（a[2n-1],a[2n]）：a[2n]=a[2n-1]+n; a[2n-1]为前2n-2项中第一个未出现的正整数；
//由beatty定理可知a[2n]=a[2n-1]*(sqrt(5)+1)/2  (向下取整)
int main()
{
	double gold = (1 + sqrt(5)) / 2;
	int n, m;
	while (cin >> n >> m) {
		int a = min(n, m), b = max(n, m);
		double k = double(b - a);
		int test = (int)(k*gold);
		if (test == a)cout << 0 << endl;
		else cout << 1 << endl;
	}
	return 0;
}