#include<bits/stdc++.h>
using namespace std;
long long res[40];
int main()
{
	res[0] = res[1] = 1;
	for (int i = 2; i <= 35; i++) {
		for (int j = 0; j < i; j++) {
			res[i] += res[j] * res[i - j - 1];
		}
	}
	int cnt = 1;
	while (1) {
		int n; cin >> n;
		if (n == -1)break;
		cout << cnt++ << " " << n << " " << res[n] * 2 << endl;
	}
	return 0;
}